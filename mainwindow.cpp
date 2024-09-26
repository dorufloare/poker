#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playingcard.h"
#include <QLabel>
#include <QPixmap>
#include <QTime>
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMyMoney(1000);
    setComputerMoney(1000);

    ResetCards();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetTurn(int player)
{
    if (player == 0)
        ui->btnCall->setText(computerBet == myBet ? "Check" : "Call");
    else ui->btnCall->setText("Check/Call");
    for (int i = 0; i < 2; ++i)
    {
        myCard[i]->MarkTurn(player == 0);
        computerCard[i]->MarkTurn(player == 1);
    }
}

void MainWindow::setPot(int _pot)
{
    pot = _pot;
    ui->lblPot->setText(QString::number(pot));
}

void MainWindow::setMyBet(int _myBet)
{
    _myBet = std::min({_myBet, computerMoney + computerBet, myMoney + myBet});
    setPot(pot - myBet + _myBet);
    setMyMoney(myMoney + myBet - _myBet);
    myBet = _myBet;
    ui->lblMyBet->setText(QString::number(myBet));
}

void MainWindow::setComputerBet(int _computerBet)
{
    _computerBet = std::min({_computerBet, myMoney + myBet, computerMoney + computerBet});
    setPot(pot - computerBet + _computerBet);
    setComputerMoney(computerMoney + computerBet - _computerBet);
    computerBet = _computerBet;
    ui->lblComputerBet->setText(QString::number(computerBet));
}

void MainWindow::setMyMoney(int _myMoney)
{
    myMoney = _myMoney;
    ui->lblMyMoney->setText(QString::number(myMoney));
}

void MainWindow::setComputerMoney(int _computerMoney)
{
    computerMoney = _computerMoney;
    ui->lblComputerMoney->setText(QString::number(computerMoney));
}

void MainWindow::FoldPlayer()
{
    myCard[0]->foldCard();
    myCard[1]->foldCard();
    AddMoneyAnimation(ui->lblPot, ui->lblComputerMoney, pot);
    computerMoney += pot;
}

void MainWindow::CallComputer()
{
    setComputerBet(myBet);
    SetTurn(0);
    RevealNextCards();
}

void MainWindow::CheckComputer()
{
    if (playerTurn == true)
        RevealNextCards();
    else
    {
        SetButtonsEnabled(true);
        SetTurn(0);
    }
}

void MainWindow::BetComputer(int bet)
{
    setComputerBet(myBet + bet);
    SetButtonsEnabled(true);
    SetTurn(0);
    if (myBet == computerBet)
        on_btnCall_clicked();
}

void MainWindow::FoldComputer()
{
    computerCard[0]->foldCard();
    computerCard[1]->foldCard();
    AddMoneyAnimation(ui->lblPot, ui->lblMyMoney, pot);
    myMoney += pot;
    SetButtonsEnabled(true);
}

void MainWindow::RevealNextCards()
{
    SetTurn(2);
    if (cardsToReveal < 6 && (myMoney == 0 || computerMoney == 0))
    {
        QTimer::singleShot(750, this, [&] {
            for (int i = 0; i < cardsToReveal; ++i)
                centralCard[i]->setRevealed(true);
            ++cardsToReveal;
            if (cardsToReveal <= 6)
                RevealNextCards();
        });
        return;
    }
    QTimer::singleShot(750, this, [&]{
        playerTurn = !playerTurn;
        if (cardsToReveal == 6)
        {
            HandleRound();
            return;
        }
        for (int i = 0; i < cardsToReveal; ++i)
            centralCard[i]->setRevealed(true);
        ++cardsToReveal;
        SetButtonsEnabled(true);
        SetTurn(0);
        if (!playerTurn)
            ComputerTurn();
    });
}

void MainWindow::HandleRound()
{
    SetTurn(2);
    computerCard[0]->setRevealed(true);
    computerCard[1]->setRevealed(true);

    winner = -1;
    int eval = Evaluate(false);

    if (eval == 0)
    {
        AddMoneyAnimation(ui->lblPot, ui->lblMyMoney, pot);
        myMoney += pot;
    }
    if (eval == 1)
    {
        AddMoneyAnimation(ui->lblPot, ui->lblComputerMoney, pot);
        computerMoney += pot;
    }
    if (eval == 2)
    {
        AddMoneyAnimation(ui->lblPot, ui->lblMyMoney, pot / 2);
        AddMoneyAnimation(ui->lblPot, ui->lblComputerMoney, pot / 2);
        myMoney += pot / 2;
        computerMoney += pot / 2;
    }
}

void MainWindow::ResetCards()
{
    CheckForRestart();
    SetButtonsEnabled(false);

    centralCard[0] = new PlayingCard(ui->centralCard1);
    centralCard[1] = new PlayingCard(ui->centralCard2);
    centralCard[2] = new PlayingCard(ui->centralCard3);
    centralCard[3] = new PlayingCard(ui->centralCard4);
    centralCard[4] = new PlayingCard(ui->centralCard5);

    computerCard[0] = new PlayingCard(ui->computerCard1);
    computerCard[1] = new PlayingCard(ui->computerCard2);

    myCard[0] = new PlayingCard(ui->myCard1);
    myCard[1] = new PlayingCard(ui->myCard2);

    SetTurn(2);

    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 5; ++j)
            PlayingCard::generated[i][j] = 0;

    winner = -1;
    cardsToReveal = 3;
    myBet = computerBet = pot = 0;
    setMyBet(0);
    setComputerBet(0);

    initComputerMoney = computerMoney;
    initMyMoney = myMoney;

    QTimer::singleShot(1500, this, [&]{
        myCard[0]->setRevealed(true);
        myCard[1]->setRevealed(true);
        ++rounds;
        playerTurn = rounds % 2;

        if (rounds == 10)
        {
            SB *= 2;
            BB *= 2;
            rounds = 1;
        }

        SetButtonsEnabled(true);
        if (playerTurn == true)
        {
            setMyBet(SB);
            setComputerBet(BB);
            ui->lblMyBlind->setPixmap((new QPixmap(":/images/sb.png"))->scaled(50, 50));
            ui->lblComputerBlind->setPixmap((new QPixmap(":/images/bb.png"))->scaled(50, 50));
            SetTurn(0);
        }
        else
        {
            setMyBet(BB);
            setComputerBet(SB);
            ui->lblMyBlind->setPixmap((new QPixmap(":/images/bb.png"))->scaled(50, 50));
            ui->lblComputerBlind->setPixmap((new QPixmap(":/images/sb.png"))->scaled(50, 50));
            SetTurn(1);
            ComputerTurn();
        }
    });
}

void MainWindow::Highlight(FullHand fh)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (myCard[j]->getSimpleCard() == fh.hi[i])
                myCard[j]->Highlight(true);
            if (computerCard[j]->getSimpleCard() == fh.hi[i])
                computerCard[j]->Highlight(true);
        }
        for (int j = 0; j < 5; ++j)
            if (centralCard[j]->getSimpleCard() == fh.hi[i])
                centralCard[j]->Highlight(true);
    }
}

void MainWindow::on_btnCall_clicked()
{
    int _myBet = myBet;
    setMyBet(computerBet);
    if (_myBet == computerBet && playerTurn)
        ComputerTurn();
    else RevealNextCards();
}

void MainWindow::on_btnAllIn_clicked()
{
    setMyBet(myBet + myMoney);
    ComputerTurn();
}

void MainWindow::on_btnBet_clicked()
{
    QString leText = ui->leBet->text();
    ui->leBet->setText("");
    int bet = leText.toInt();
    if (leText == "" || bet <= 0)
        return;

    bet += computerBet - myBet;

    setMyBet(std::min({myBet + bet, computerMoney + computerBet, myBet + myMoney}));
    ComputerTurn();
}

void MainWindow::on_btnFold_clicked()
{
    FoldPlayer();
}

void MainWindow::SetButtonsEnabled(bool enabled)
{
    ui->btnFold->setEnabled(enabled);
    ui->btnAllIn->setEnabled(enabled);

    ui->btnCall->setEnabled(enabled);
    ui->btnBet->setEnabled(enabled);
}

void MainWindow::AddMoneyAnimation(QLabel* src, QLabel* dest, int transfer)
{
    if (transfer <= 0)
    {
        QTimer::singleShot(3000, this, [&]{ResetCards();});
        return;
    }
    QTimer::singleShot(1, this, [=](){
        src->setText(QString::number(src->text().toInt() - 1));
        dest->setText(QString::number(dest->text().toInt() + 1));
        AddMoneyAnimation(src, dest, transfer - 1);
    });
}

void MainWindow::CheckForRestart()
{
    if (myMoney == 0)
        QMessageBox::information(this, "GAME OVER", "YOU LOST!");
    if (computerMoney == 0)
        QMessageBox::information(this, "GAME OVER", "YOU WON!");
    if (myMoney == 0 || computerMoney == 0)
    {
        setMyMoney(1000);
        setComputerMoney(1000);
        SB = 10;
        BB = 20;
        playerTurn = 0;
        rounds = 0;
        ResetCards();
    }
}
