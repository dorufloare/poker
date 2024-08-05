#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playingcard.h"

#include <QLabel>
#include <QPixmap>
#include <QTime>
#include <QTimer>


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

void MainWindow::setPot(int _pot)
{
    pot = _pot;
    ui->lblPot->setText(QString::number(pot));
}

void MainWindow::setMyBet(int _myBet)
{
    setPot(pot - myBet + _myBet);
    setMyMoney(myMoney + myBet - _myBet);
    myBet = _myBet;
    ui->lblMyBet->setText(QString::number(myBet));
}

void MainWindow::setComputerBet(int _computerBet)
{
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
    setMyMoney(myMoney - pot);
    setComputerMoney(computerMoney + pot);
    QTimer::singleShot(1500, this, [&]{ResetCards();});
}

void MainWindow::ComputerTurn()
{
    int decision = rand() % 3;
    if (decision == 0)
        CallComputer();
    if (decision == 1) BetComputer();
    if (decision == 2) FoldComputer();
}

void MainWindow::CallComputer()
{
    setComputerBet(myBet);
    RevealNextCards();
}

void MainWindow::BetComputer()
{
    setComputerBet(myBet + 20);
}

void MainWindow::FoldComputer()
{
    computerCard[0]->foldCard();
    computerCard[1]->foldCard();
    setMyMoney(myMoney + pot);
    QTimer::singleShot(1500, this, [&]{ResetCards();});
}

void MainWindow::RevealNextCards()
{
    QTimer::singleShot(750, this, [&]{
        if (cardsToReveal == 6)
        {
            computerCard[0]->setRevealed(true);
            computerCard[1]->setRevealed(true);
            QTimer::singleShot(1500, this, [&]{ResetCards();});
        }
        for (int i = 0; i < cardsToReveal; ++i)
            centralCard[i]->setRevealed(true);
        ++cardsToReveal;
    });
}

void MainWindow::ResetCards()
{
    centralCard[0] = new PlayingCard(ui->centralCard1);
    centralCard[1] = new PlayingCard(ui->centralCard2);
    centralCard[2] = new PlayingCard(ui->centralCard3);
    centralCard[3] = new PlayingCard(ui->centralCard4);
    centralCard[4] = new PlayingCard(ui->centralCard5);

    computerCard[0] = new PlayingCard(ui->computerCard1);
    computerCard[1] = new PlayingCard(ui->computerCard2);

    myCard[0] = new PlayingCard(ui->myCard1);
    myCard[1] = new PlayingCard(ui->myCard2);

    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 5; ++j)
            PlayingCard::generated[i][j] = 0;

    cardsToReveal = 3;
    myBet = computerBet = pot = 0;
    setMyBet(0);
    setComputerBet(0);

    QTimer::singleShot(1500, this, [&]{
        myCard[0]->setRevealed(true);
        myCard[1]->setRevealed(true);
        setMyBet(SB);
        setComputerBet(BB);
    });
}

void MainWindow::on_btnCall_clicked()
{
    setMyBet(computerBet);
    RevealNextCards();
}

void MainWindow::on_btnAllIn_clicked()
{
    setMyBet(myBet + myMoney);
    ComputerTurn();
}

void MainWindow::on_btnBet_clicked()
{
    QString leText = ui->leBet->text();
    int bet = leText.toInt();
    if (leText == "" || bet <= 0)
        return;

    bet = std::min(bet, myMoney);
    setMyBet(myBet + bet);
    ComputerTurn();
}

void MainWindow::on_btnFold_clicked()
{
    FoldPlayer();
}


void MainWindow::on_btnCheck_clicked()
{
    ComputerTurn();
}

