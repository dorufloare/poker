#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <QLabel>
#include <map>

enum CardType {
    hearts = 1,
    spades = 2,
    clubs = 3,
    diamonds = 4
};

class PlayingCard
{
public:
    inline static bool generated[15][5] = {0};

    PlayingCard();
    PlayingCard(QLabel* lblCard);
    PlayingCard(int number, CardType cardType);
    ~PlayingCard();

    QString getFilename();
    void GenerateRandom();
    void setRevealed(bool const& _revealed);
    void setImage(QString const& filename);
    void foldCard();
private:
    QLabel* lblCard;

    bool revealed;
    bool folded;

    int number;
    CardType cardType;
};

#endif // PLAYINGCARD_H
