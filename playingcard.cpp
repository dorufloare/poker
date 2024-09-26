#include "playingcard.h"
#include <QRandomGenerator>
#include <QBitmap>
#include <QPainter>

PlayingCard::PlayingCard()
{
    Highlight(false);
}

void PlayingCard::Remove()
{
    generated[number][cardType] = false;
}

void PlayingCard::Add()
{
    generated[number][cardType] = true;
}

bool PlayingCard::isRevealed()
{
    return revealed;
}

PlayingCard::PlayingCard(QLabel* lblCard) : lblCard(lblCard)
{
    setImage("back.png");
    GenerateRandom();
    Highlight(false);
}

PlayingCard::PlayingCard(int number, CardType cardType) : number(number), cardType(cardType)
{
    lblCard = nullptr;
    revealed = false;
    Highlight(false);
}

PlayingCard::~PlayingCard()
{
    Remove();
}

QString PlayingCard::getFilename()
{
    QString filename = QString::number(number);
    if (cardType == spades)   filename += "s";
    if (cardType == hearts)   filename += "h";
    if (cardType == diamonds) filename += "d";
    if (cardType == clubs)    filename += "c";

    return filename;
}

void PlayingCard::GenerateRandom()
{
    do
    {
        number = QRandomGenerator::global()->bounded(2, 15);
        cardType = static_cast<CardType>(QRandomGenerator::global()->bounded(1, 5));
    } while (generated[number][cardType] == true);
    generated[number][cardType] = true;
}

void PlayingCard::setRevealed(bool const& _revealed)
{
    revealed = _revealed;
    if (revealed)
        setImage(getFilename());
    else setImage("back.png");
}

void PlayingCard::setImage(QString const& filename)
{
    lblCard->setPixmap((new QPixmap(":/images/" + filename))->scaled(W, H));
}

void PlayingCard::foldCard()
{
    setImage("fold_back.png");
}

SimpleCard PlayingCard::getSimpleCard()
{
    return std::make_pair(number, cardType);
}

void PlayingCard::setSimpleCard(SimpleCard sc)
{
    number = sc.first;
    cardType = sc.second;
}

void PlayingCard::Highlight(bool status)
{
    if (status == true)
        lblCard->setStyleSheet("border: 8px solid yellow;");
    else lblCard->setStyleSheet("border: 5px solid black;");
}

void PlayingCard::MarkTurn(bool turn)
{
    if (turn)
        lblCard->setStyleSheet("border: 8px solid #73FF33;");
    else lblCard->setStyleSheet("border: 5px solid black;");
}
