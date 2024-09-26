#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "playingcard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct FullHand
{
    int form = 0;
    std::vector<SimpleCard> hi = {};
    int rank = 0;

    friend bool operator < (const FullHand& fh1, const FullHand& fh2)
    {
        if (fh1.form != fh2.form)
            return fh1.form < fh2.form;
        return fh1.hi < fh2.hi;
    }
    friend bool operator > (const FullHand& fh1, const FullHand& fh2)
    {
        if (fh1.form != fh2.form)
            return fh1.form > fh2.form;
        return fh1.hi > fh2.hi;
    }
    friend bool operator == (const FullHand& fh1, const FullHand& fh2)
    {
        return (fh1.form == fh2.form && fh1.hi == fh2.hi);
    }
    void addCards(std::vector<SimpleCard> newCards)
    {
        for (auto i : newCards)
            hi.push_back(i);
    }
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ResetCards();
    void SetButtonsEnabled(bool enabled);
    void Flop();
    void Turn();
    void River();
    void setMyBet(int _myBet);
    void setComputerMoney(int _computerMoney);
    void setMyMoney(int _myMoney);
    void setComputerBet(int _computerBet);
    void setPot(int _pot);
    void RevealNextCards();
    void FoldPlayer();
    void FoldComputer();
    void ComputerTurn();
    void CallComputer();
    void BetComputer(int bet);
    void CheckComputer();
    void HandleRound();
    void Highlight(FullHand fh);
    void SetTurn(int player);
    int Evaluate(bool ai_generated);
    void SimulateTurns(int nrTurns, int& wins, int& loses, int& draws);
    FullHand CheckStraightFlush(bool player);
    FullHand CheckQuads(bool player);
    FullHand CheckFullHouse(bool player);
    FullHand CheckFlush(bool player);
    FullHand CheckStraight(bool player);
    FullHand CheckTrips(bool player);
    FullHand Check2Pairs(bool player);
    FullHand CheckPair(bool player);
    FullHand CheckHighCard(bool player);
    void CheckForRestart();
    void Manage(FullHand myResul, FullHand computerResult, bool ai_generated);
    void getCards(bool (&card)[15][5], bool player);
    void AddMoneyAnimation(QLabel* src, QLabel* dest, int transfer);
    std::vector<SimpleCard> getHighestCards(bool (&card)[15][5], int k);

private slots:
    void on_btnCall_clicked();
    void on_btnAllIn_clicked();
    void on_btnBet_clicked();

    void on_btnFold_clicked();

    void on_btnCheck_clicked(){};

private:
    Ui::MainWindow *ui;

    PlayingCard *centralCard[5];
    PlayingCard *computerCard[2];
    PlayingCard *myCard[2];

    int pot = 0, myBet = 0, computerBet = 0;
    int BB = 20, SB = 10;
    int cardsToReveal = 3;
    int rounds = 0;
    int myMoney;
    int computerMoney;
    int winner = -1;
    bool playerTurn = true;
    int initComputerMoney;
    int initMyMoney;
};
#endif // MAINWINDOW_H
