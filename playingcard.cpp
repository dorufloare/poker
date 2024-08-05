#include "playingcard.h"
#include <QRandomGenerator>

int Random(int const& low, int const& high)
{
    return QRandomGenerator::global()->generate() % (high - low + 1) + low;
}

PlayingCard::PlayingCard()
{
    GenerateRandom();
}

PlayingCard::PlayingCard(QLabel* lblCard) : lblCard(lblCard)
{
    lblCard->setPixmap((new QPixmap(":/images/back.png"))->scaled(QSize(75,99)));
    GenerateRandom();
}

PlayingCard::PlayingCard(int number, CardType cardType) : number(number), cardType(cardType)
{
    lblCard = nullptr;
    revealed = false;
}

PlayingCard::~PlayingCard()
{
    generated[number][cardType] = false;
}

QString PlayingCard::getFilename()
{
    QString filename = QString::number(number);
    if (cardType == spades)   filename += "_of_spades.png";
    if (cardType == hearts)   filename += "_of_hearts.png";
    if (cardType == diamonds) filename += "_of_diamonds.png";
    if (cardType == clubs)    filename += "_of_clubs.png";

    return filename;
}

void PlayingCard::GenerateRandom()
{
    do
    {
        number = Random(2, 14);
        cardType = static_cast<CardType>(Random(1, 4));
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
    lblCard->setPixmap((new QPixmap(":/images/" + filename))->scaled(QSize(80,100)));
}

void PlayingCard::foldCard()
{
    setImage("fold_back.png");
}
