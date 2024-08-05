#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "playingcard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ResetCards();
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
    void BetComputer();

private slots:
    void on_btnCall_clicked();
    void on_btnAllIn_clicked();
    void on_btnBet_clicked();

    void on_btnFold_clicked();

    void on_btnCheck_clicked();

private:
    Ui::MainWindow *ui;

    PlayingCard *centralCard[5];
    PlayingCard *computerCard[2];
    PlayingCard *myCard[2];

    int pot = 0, myBet = 0, computerBet = 0;
    int BB = 20, SB = 10;
    int cardsToReveal = 3;

    int myMoney;
    int computerMoney;

};
#endif // MAINWINDOW_H
