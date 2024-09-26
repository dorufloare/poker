/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *computerHandLayout;
    QLabel *computerCard2;
    QLabel *computerCard1;
    QWidget *layoutWidget1;
    QGridLayout *centralCardsLayout;
    QLabel *centralCard4;
    QLabel *centralCard2;
    QLabel *centralCard3;
    QLabel *centralCard1;
    QLabel *centralCard5;
    QWidget *layoutWidget2;
    QGridLayout *myHandLayout;
    QLabel *myCard1;
    QLabel *myCard2;
    QLineEdit *leBet;
    QLabel *lblMyMoney;
    QLabel *lblComputerMoney;
    QLabel *lblMyBet;
    QLabel *lblComputerBet;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QPushButton *btnBet;
    QPushButton *btnCall;
    QPushButton *btnAllIn;
    QPushButton *btnFold;
    QLabel *lblPot;
    QPushButton *btnCheck;
    QLabel *lblMyBlind;
    QLabel *lblComputerBlind;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1400, 800);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{background-image: url(:/images/table.png)};\n"
"background-image: url(:/images/table.png);"));
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(1130, 140, 241, 151));
        QFont font;
        font.setFamilies({QString::fromUtf8("Gill Sans MT")});
        font.setPointSize(26);
        font.setBold(false);
        layoutWidget->setFont(font);
        layoutWidget->setStyleSheet(QString::fromUtf8(""));
        computerHandLayout = new QGridLayout(layoutWidget);
        computerHandLayout->setObjectName("computerHandLayout");
        computerHandLayout->setContentsMargins(0, 0, 0, 0);
        computerCard2 = new QLabel(layoutWidget);
        computerCard2->setObjectName("computerCard2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Franklin Gothic Demi")});
        font1.setPointSize(28);
        font1.setBold(false);
        computerCard2->setFont(font1);
        computerCard2->setAutoFillBackground(false);
        computerCard2->setStyleSheet(QString::fromUtf8(""));
        computerCard2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        computerHandLayout->addWidget(computerCard2, 0, 1, 1, 1);

        computerCard1 = new QLabel(layoutWidget);
        computerCard1->setObjectName("computerCard1");
        computerCard1->setFont(font);
        computerCard1->setAutoFillBackground(false);
        computerCard1->setStyleSheet(QString::fromUtf8(""));
        computerCard1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        computerHandLayout->addWidget(computerCard1, 0, 0, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(380, 300, 601, 151));
        layoutWidget1->setFont(font);
        layoutWidget1->setStyleSheet(QString::fromUtf8(""));
        centralCardsLayout = new QGridLayout(layoutWidget1);
        centralCardsLayout->setObjectName("centralCardsLayout");
        centralCardsLayout->setHorizontalSpacing(0);
        centralCardsLayout->setVerticalSpacing(6);
        centralCardsLayout->setContentsMargins(0, 0, 0, 0);
        centralCard4 = new QLabel(layoutWidget1);
        centralCard4->setObjectName("centralCard4");
        centralCard4->setFont(font);
        centralCard4->setAutoFillBackground(false);
        centralCard4->setStyleSheet(QString::fromUtf8(""));
        centralCard4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        centralCardsLayout->addWidget(centralCard4, 0, 3, 1, 1);

        centralCard2 = new QLabel(layoutWidget1);
        centralCard2->setObjectName("centralCard2");
        centralCard2->setFont(font);
        centralCard2->setAutoFillBackground(false);
        centralCard2->setStyleSheet(QString::fromUtf8(""));
        centralCard2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        centralCardsLayout->addWidget(centralCard2, 0, 1, 1, 1);

        centralCard3 = new QLabel(layoutWidget1);
        centralCard3->setObjectName("centralCard3");
        centralCard3->setFont(font);
        centralCard3->setAutoFillBackground(false);
        centralCard3->setStyleSheet(QString::fromUtf8(""));
        centralCard3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        centralCardsLayout->addWidget(centralCard3, 0, 2, 1, 1);

        centralCard1 = new QLabel(layoutWidget1);
        centralCard1->setObjectName("centralCard1");
        centralCard1->setFont(font);
        centralCard1->setAutoFillBackground(false);
        centralCard1->setStyleSheet(QString::fromUtf8(""));
        centralCard1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        centralCardsLayout->addWidget(centralCard1, 0, 0, 1, 1);

        centralCard5 = new QLabel(layoutWidget1);
        centralCard5->setObjectName("centralCard5");
        centralCard5->setFont(font);
        centralCard5->setAutoFillBackground(false);
        centralCard5->setStyleSheet(QString::fromUtf8(""));
        centralCard5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        centralCardsLayout->addWidget(centralCard5, 0, 4, 1, 1);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(50, 150, 241, 151));
        layoutWidget2->setFont(font);
        layoutWidget2->setStyleSheet(QString::fromUtf8(""));
        myHandLayout = new QGridLayout(layoutWidget2);
        myHandLayout->setObjectName("myHandLayout");
        myHandLayout->setContentsMargins(0, 0, 0, 0);
        myCard1 = new QLabel(layoutWidget2);
        myCard1->setObjectName("myCard1");
        myCard1->setFont(font);
        myCard1->setAutoFillBackground(false);
        myCard1->setStyleSheet(QString::fromUtf8(""));
        myCard1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        myHandLayout->addWidget(myCard1, 0, 1, 1, 1);

        myCard2 = new QLabel(layoutWidget2);
        myCard2->setObjectName("myCard2");
        myCard2->setFont(font);
        myCard2->setAutoFillBackground(false);
        myCard2->setStyleSheet(QString::fromUtf8(""));
        myCard2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        myHandLayout->addWidget(myCard2, 0, 0, 1, 1);

        leBet = new QLineEdit(centralwidget);
        leBet->setObjectName("leBet");
        leBet->setGeometry(QRect(520, 690, 331, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Gill Sans MT")});
        font2.setPointSize(17);
        font2.setBold(true);
        leBet->setFont(font2);
        leBet->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;\n"
"border-radius: 25px;\n"
"background-color: rgb(47, 56, 49);"));
        lblMyMoney = new QLabel(centralwidget);
        lblMyMoney->setObjectName("lblMyMoney");
        lblMyMoney->setGeometry(QRect(50, 70, 241, 71));
        lblMyMoney->setFont(font);
        lblMyMoney->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lblMyMoney->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;border-radius: 25px;\n"
"\n"
"background-color: rgb(47, 56, 49);"));
        lblMyMoney->setTextFormat(Qt::TextFormat::AutoText);
        lblMyMoney->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblComputerMoney = new QLabel(centralwidget);
        lblComputerMoney->setObjectName("lblComputerMoney");
        lblComputerMoney->setGeometry(QRect(1130, 60, 241, 71));
        lblComputerMoney->setFont(font);
        lblComputerMoney->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lblComputerMoney->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;border-radius: 25px;\n"
"\n"
"background-color: rgb(47, 56, 49);"));
        lblComputerMoney->setTextFormat(Qt::TextFormat::AutoText);
        lblComputerMoney->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblMyBet = new QLabel(centralwidget);
        lblMyBet->setObjectName("lblMyBet");
        lblMyBet->setGeometry(QRect(220, 410, 141, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Gill Sans MT")});
        font3.setPointSize(20);
        font3.setBold(false);
        lblMyBet->setFont(font3);
        lblMyBet->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;border-radius: 25px;\n"
"\n"
"background-color: rgb(47, 56, 49);"));
        lblMyBet->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblComputerBet = new QLabel(centralwidget);
        lblComputerBet->setObjectName("lblComputerBet");
        lblComputerBet->setGeometry(QRect(1020, 420, 141, 71));
        lblComputerBet->setFont(font3);
        lblComputerBet->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;border-radius: 25px;\n"
"\n"
"background-color: rgb(47, 56, 49);"));
        lblComputerBet->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(330, 590, 701, 91));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(layoutWidget3->sizePolicy().hasHeightForWidth());
        layoutWidget3->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Gill Sans MT")});
        font4.setPointSize(22);
        font4.setBold(true);
        layoutWidget3->setFont(font4);
        layoutWidget3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        layoutWidget3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;\n"
"\n"
"background-color: rgb(47, 56, 49);"));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnBet = new QPushButton(layoutWidget3);
        btnBet->setObjectName("btnBet");
        sizePolicy.setHeightForWidth(btnBet->sizePolicy().hasHeightForWidth());
        btnBet->setSizePolicy(sizePolicy);
        btnBet->setFont(font4);
        btnBet->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnBet->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;\n"
"\n"
"background-color: rgb(47, 56, 49);"));

        gridLayout->addWidget(btnBet, 0, 2, 1, 1);

        btnCall = new QPushButton(layoutWidget3);
        btnCall->setObjectName("btnCall");
        sizePolicy.setHeightForWidth(btnCall->sizePolicy().hasHeightForWidth());
        btnCall->setSizePolicy(sizePolicy);
        btnCall->setFont(font4);
        btnCall->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnCall->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;\n"
"\n"
"background-color: rgb(47, 56, 49);"));

        gridLayout->addWidget(btnCall, 0, 1, 1, 1);

        btnAllIn = new QPushButton(layoutWidget3);
        btnAllIn->setObjectName("btnAllIn");
        sizePolicy.setHeightForWidth(btnAllIn->sizePolicy().hasHeightForWidth());
        btnAllIn->setSizePolicy(sizePolicy);
        btnAllIn->setFont(font4);
        btnAllIn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnAllIn->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;\n"
"\n"
"background-color: rgb(47, 56, 49);"));

        gridLayout->addWidget(btnAllIn, 0, 3, 1, 1);

        btnFold = new QPushButton(layoutWidget3);
        btnFold->setObjectName("btnFold");
        sizePolicy.setHeightForWidth(btnFold->sizePolicy().hasHeightForWidth());
        btnFold->setSizePolicy(sizePolicy);
        btnFold->setFont(font4);
        btnFold->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnFold->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;\n"
"\n"
"background-color: rgb(47, 56, 49);"));

        gridLayout->addWidget(btnFold, 0, 4, 1, 1);

        lblPot = new QLabel(centralwidget);
        lblPot->setObjectName("lblPot");
        lblPot->setGeometry(QRect(590, 90, 201, 101));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Gill Sans MT")});
        font5.setPointSize(25);
        font5.setBold(false);
        lblPot->setFont(font5);
        lblPot->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); border: 3px solid white;border-radius: 25px;\n"
"\n"
"background-color: rgb(47, 56, 49);"));
        lblPot->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btnCheck = new QPushButton(centralwidget);
        btnCheck->setObjectName("btnCheck");
        btnCheck->setGeometry(QRect(410, 510, 0, 0));
        lblMyBlind = new QLabel(centralwidget);
        lblMyBlind->setObjectName("lblMyBlind");
        lblMyBlind->setGeometry(QRect(230, 540, 51, 51));
        lblComputerBlind = new QLabel(centralwidget);
        lblComputerBlind->setObjectName("lblComputerBlind");
        lblComputerBlind->setGeometry(QRect(1080, 540, 51, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1400, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Poker!", nullptr));
        computerCard2->setText(QString());
        computerCard1->setText(QString());
        centralCard4->setText(QString());
        centralCard2->setText(QString());
        centralCard3->setText(QString());
        centralCard1->setText(QString());
        centralCard5->setText(QString());
        myCard1->setText(QString());
        myCard2->setText(QString());
        leBet->setText(QString());
        lblMyMoney->setText(QString());
        lblComputerMoney->setText(QString());
        lblMyBet->setText(QString());
        lblComputerBet->setText(QString());
        btnBet->setText(QCoreApplication::translate("MainWindow", "Bet", nullptr));
        btnCall->setText(QCoreApplication::translate("MainWindow", "Check/Call", nullptr));
        btnAllIn->setText(QCoreApplication::translate("MainWindow", "All In", nullptr));
        btnFold->setText(QCoreApplication::translate("MainWindow", "Fold", nullptr));
        lblPot->setText(QString());
        btnCheck->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        lblMyBlind->setText(QString());
        lblComputerBlind->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
