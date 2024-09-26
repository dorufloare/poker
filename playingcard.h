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

using SimpleCard = std::pair<int,CardType>;

class PlayingCard
{
public:
    inline static bool generated[15][5]{};

    PlayingCard();
    PlayingCard(QLabel* lblCard);
    PlayingCard(int number, CardType cardType);

    ~PlayingCard();

    QString getFilename();
    void GenerateRandom();
    void setRevealed(bool const& _revealed);
    void setImage(QString const& filename);
    void foldCard();
    bool isRevealed();
    void Remove();
    void Add();
    void Highlight(bool status);
    void MarkTurn(bool turn);
    SimpleCard getSimpleCard();
    void setSimpleCard(SimpleCard sc);

    int number;
    CardType cardType;
private:
    QLabel* lblCard;

    bool revealed;
    bool folded;

    const int H = 142;
    const int W = 117;
};

#endif // PLAYINGCARD_H
