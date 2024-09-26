#include "mainwindow.h"
#include "playingcard.h"
#include <QRandomGenerator>
#include <QTimer>

int HighBet()
{
    return QRandomGenerator::global()->bounded(200, 2001);
}
int MediumBet()
{
    return QRandomGenerator::global()->bounded(100, 200);
}
int SmallBet()
{
    return QRandomGenerator::global()->bounded(1, 100);
}

bool isHighBet(int bet)
{
    return (bet >= 200);
}
bool isMediumBet(int bet)
{
    return (100 <= bet && bet < 200);
}
bool isSmallBet(int bet)
{
    return (bet < 100);
}

bool Chance(int k)
{
    return (QRandomGenerator::global()->bounded(0, k) == 1);
}

void MainWindow::ComputerTurn()
{
    SetTurn(1);
    SetButtonsEnabled(false);

    QTimer::singleShot(1500, this, [&]{
        int wins = 0, loses = 0, draws = 0;

        SimulateTurns(100, wins, loses, draws);
        qDebug() << wins << loses << draws;

        wins += draws;

        if (computerBet == myBet)
        {
            if (wins < 50)
                CheckComputer();
            else if (wins < 65)
                BetComputer(SmallBet());
            else if (wins < 80)
                BetComputer(MediumBet());
            else BetComputer(HighBet());
        }
        else
        {
            int playerBet = myBet - computerBet;

            if (wins < 40)
                FoldComputer();
            else if (wins < 55)
            {
                if (isSmallBet(playerBet))
                    CallComputer();
                else if (isMediumBet(playerBet))
                    FoldComputer();
                else if (isHighBet(playerBet))
                    FoldComputer();
            }
            else if (wins < 70)
            {
                if (isSmallBet(playerBet))
                {
                    if (Chance(5))
                        BetComputer(SmallBet());
                    else CallComputer();
                }
                else if (isMediumBet(playerBet))
                {
                    if (Chance(2))
                        CallComputer();
                    else FoldComputer();
                }
                else if (isHighBet(playerBet))
                    FoldComputer();
            }
            else if (wins < 95)
            {
                if (isSmallBet(playerBet))
                {
                    BetComputer(SmallBet());
                }
                else if (isMediumBet(playerBet))
                {
                    CallComputer();
                }
                else if (isHighBet(playerBet))
                {
                    if (wins < 85 && Chance(2))
                        FoldComputer();
                    else CallComputer();
                }
            }
            else
            {
                if (Chance(3))
                    BetComputer(MediumBet());
                else BetComputer(HighBet());
            }
        }

        SetButtonsEnabled(true);
    });
}

void MainWindow::SimulateTurns(int nrTurns, int& wins, int& loses, int& draws)
{
    SimpleCard myCardSave[2];
    SimpleCard centralCardSave[5];

    myCardSave[0] = myCard[0]->getSimpleCard();
    myCardSave[1] = myCard[1]->getSimpleCard();
    for (int i = 0; i < 5; ++i)
        centralCardSave[i] = centralCard[i]->getSimpleCard();

    myCard[0]->Remove();
    myCard[1]->Remove();
    for (int i = 0; i < 5; ++i)
        if (!centralCard[i]->isRevealed())
            centralCard[i]->Remove();

    while (nrTurns--)
    {
        myCard[0]->GenerateRandom();
        myCard[1]->GenerateRandom();

        for (int i = 0; i < 5; ++i)
            if (!centralCard[i]->isRevealed())
                centralCard[i]->GenerateRandom();

        winner = -1;
        int outcome = Evaluate(true);
        if (outcome == 0) ++loses;
        if (outcome == 1) ++wins;
        if (outcome == 2) ++draws;

        myCard[0]->Remove();
        myCard[1]->Remove();
        for (int i = 0; i < 5; ++i)
            if (!centralCard[i]->isRevealed())
                centralCard[i]->Remove();
    }
    myCard[0]->setSimpleCard(myCardSave[0]);
    myCard[1]->setSimpleCard(myCardSave[1]);
    for (int i = 0; i < 5; ++i)
        centralCard[i]->setSimpleCard(centralCardSave[i]);

    myCard[0]->Add();
    myCard[1]->Add();
    for (int i = 0; i < 5; ++i)
        centralCard[i]->Add();
}

void MainWindow::getCards(bool (&card)[15][5], bool player)
{
    for (int i = 0; i < 5; ++i)
        card[centralCard[i]->number][centralCard[i]->cardType] = true;

    if (player == 0)
    {
        card[myCard[0]->number][myCard[0]->cardType] = true;
        card[myCard[1]->number][myCard[1]->cardType] = true;
    }
    if (player == 1)
    {
        card[computerCard[0]->number][computerCard[0]->cardType] = true;
        card[computerCard[1]->number][computerCard[1]->cardType] = true;
    }
    for (int i = 1; i <= 4; ++i)
        card[1][i] = card[14][i];
}
std::vector<SimpleCard> MainWindow::getHighestCards(bool (&card)[15][5], int k)
{
    std::vector<SimpleCard> cards;
    for (int i = 14; i >= 2 && (int)cards.size() < k; --i)
    {
        for (int j = 1; j <= 4 && (int)cards.size() < k; ++j)
            if (card[i][j])
                cards.push_back({i, static_cast<CardType>(j)});
    }
    return cards;
}

void MainWindow::Manage(FullHand myResult, FullHand computerResult, bool ai_generated)
{
    if (myResult.form == 0 && computerResult.form == 0)
        return;

    if (!ai_generated)
    {
        if (myResult.form) qDebug() << myResult.rank;
        if (computerResult.form) qDebug() << computerResult.rank;
    }

    if (myResult == computerResult)
    {
        winner = 2;
        return;
    }
    if (myResult < computerResult)
    {
        winner = 1;
        if (ai_generated == false)
            Highlight(computerResult);
        return;
    }

    winner = 0;
    if (ai_generated == false)
        Highlight(myResult);
    return;

}

int MainWindow::Evaluate(bool ai_generated)
{
    if (winner == -1) Manage(CheckStraightFlush(0), CheckStraightFlush(1), ai_generated);
    if (winner == -1) Manage(CheckQuads(0), CheckQuads(1), ai_generated);
    if (winner == -1) Manage(CheckFullHouse(0), CheckFullHouse(1), ai_generated);
    if (winner == -1) Manage(CheckFlush(0), CheckFlush(1), ai_generated);
    if (winner == -1) Manage(CheckStraight(0), CheckStraight(1), ai_generated);
    if (winner == -1) Manage(CheckTrips(0), CheckTrips(1), ai_generated);
    if (winner == -1) Manage(Check2Pairs(0), Check2Pairs(1), ai_generated);
    if (winner == -1) Manage(CheckPair(0), CheckPair(1), ai_generated);
    if (winner == -1) Manage(CheckHighCard(0), CheckHighCard(1), ai_generated);

    if (winner == -1)
        winner = 2;
    return winner;
}

FullHand MainWindow::CheckStraightFlush(bool player)
{
    FullHand fh;
    bool card[15][5]{};
    getCards(card, player);

    for (int t = 1; t <= 4; ++t)
    {
        for (int i = 10; i >= 1; --i)
        {
            bool ok = true;
            for (int j = i + 4; j >= i; --j)
                ok &= (card[j][t]);
            if (!ok) continue;

            for (int j = i + 4; j >= i; --j)
                if (card[j][t])
                {
                    card[j][t] = 0;
                    fh.hi.push_back({(j == 1 ? 14 : j), static_cast<CardType>(t)});
                    fh.form = 1;
                    fh.rank = 1;
                }
            return fh;
        }
    }
    return fh;
}
FullHand MainWindow::CheckQuads(bool player)
{
    FullHand fh;
    bool card[15][5]{};
    getCards(card, player);

    for (int i = 14; i >= 2; --i)
    {
        if (card[i][1] + card[i][2] + card[i][3] + card[i][4] >= 4)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (card[i][j] == 0) continue;
                card[i][j] = 0;
                fh.hi.push_back({i, static_cast<CardType>(j)});
            }
            fh.form = 1;
            fh.rank = 2;
            break;
        }
    }
    fh.addCards(getHighestCards(card, 1));
    return fh;
}
FullHand MainWindow::CheckFullHouse(bool player)
{
    FullHand fh;
    bool card[15][5]{};
    getCards(card, player);

    for (int i = 14; i >= 2; --i)
    {
        if (card[i][1] + card[i][2] + card[i][3] + card[i][4] >= 3)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (card[i][j] == 0) continue;
                card[i][j] = 0;
                fh.hi.push_back({i, static_cast<CardType>(j)});
            }
            break;
        }
    }
    if (fh.hi.empty())
        return fh;

    for (int i = 14; i >= 2; --i)
    {
        if (card[i][1] + card[i][2] + card[i][3] + card[i][4] >= 2 && i != fh.hi[0].first)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (card[i][j] == 0) continue;
                card[i][j] = 0;
                fh.hi.push_back({i, static_cast<CardType>(j)});
            }
            fh.form = 1;
            fh.rank = 3;
            break;
        }
    }
    return fh;
}
FullHand MainWindow::CheckFlush(bool player)
{
    FullHand fh;
    bool card[15][5]{};
    getCards(card, player);

    for (int t = 1; t <= 4; ++t)
    {
        for (int i = 14; i >= 2 && fh.hi.size() < 5; --i)
            if (card[i][t])
                fh.hi.push_back({i, static_cast<CardType>(t)});
        if (fh.hi.size() == 5)
        {
            fh.form = 1;
            fh.rank = 4;
            return fh;
        }
        fh.hi.clear();
    }
    return fh;
}
FullHand MainWindow::CheckStraight(bool player)
{
    FullHand fh;
    bool card[15][5]{};
    getCards(card, player);

    for (int i = 10; i >= 1; --i)
    {
        bool ok = true;
        for (int j = i + 4; j >= i; --j)
            ok &= (card[j][1] | card[j][2] | card[j][3] | card[j][4]);
        if (!ok) continue;

        for (int j = i + 4; j >= i; --j)
            for (int t = 1; t <= 4; ++t)
                if (card[j][t])
                {
                    card[j][t] = 0;
                    fh.hi.push_back({(j == 1 ? 14 : j), static_cast<CardType>(t)});
                    fh.form = 1;
                    fh.rank = 5;
                    break;
                }
        return fh;
    }
    return fh;
}
FullHand MainWindow::CheckTrips(bool player)
{
    FullHand fh;
    bool card[15][5]{};
    getCards(card, player);

    for (int i = 14; i >= 2; --i)
    {
        if (card[i][1] + card[i][2] + card[i][3] + card[i][4] >= 3)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (card[i][j] == 0) continue;
                card[i][j] = 0;
                fh.hi.push_back({i, static_cast<CardType>(j)});
            }
            fh.form = 1;
            fh.rank = 6;
            break;
        }
    }
    fh.addCards(getHighestCards(card, 2));
    return fh;
}
FullHand MainWindow::Check2Pairs(bool player)
{
    FullHand fh;
    bool card[15][5]{};
    getCards(card, player);
    int cnt = 0;

    for (int i = 14; i >= 2; --i)
    {
        if (card[i][1] + card[i][2] + card[i][3] + card[i][4] >= 2)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (card[i][j] == 0) continue;
                card[i][j] = 0;
                fh.hi.push_back({i, static_cast<CardType>(j)});
            }
            ++cnt;
            if (cnt == 2)
            {
                fh.form = 1;
                fh.rank = 7;
                break;
            }
        }
    }
    fh.addCards(getHighestCards(card, 1));
    return fh;
}
FullHand MainWindow::CheckPair(bool player)
{
    FullHand fh;
    bool card[15][5]{};
    getCards(card, player);

    for (int i = 14; i >= 2; --i)
    {
        if (card[i][1] + card[i][2] + card[i][3] + card[i][4] >= 2)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (card[i][j] == 0) continue;
                card[i][j] = 0;
                fh.hi.push_back({i, static_cast<CardType>(j)});
            }
            fh.form = 1;
            fh.rank = 8;
            break;
        }
    }
    fh.addCards(getHighestCards(card, 3));
    return fh;
}
FullHand MainWindow::CheckHighCard(bool player)
{
    FullHand fh;
    bool card[15][5]{};
    getCards(card, player);

    fh.hi = getHighestCards(card, 5);
    fh.form = 1;
    fh.rank = 9;
    return fh;
}
