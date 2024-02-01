#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include <vector>
#include <string>

class Card {
public:
    enum class Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
    enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

    Card(Rank r, Suit s) : rank(r), suit(s) {}

    int GetValue() const;

private:
    Rank rank;
    Suit suit;
};

class Deck {
public:
    Deck();

    void Shuffle();
    Card DealCard();

private:
    std::vector<Card> cards;
};

class BlackjackGame {
public:
    void Play();

private:
    Deck deck;
    std::vector<Card> playerHand;
    std::vector<Card> dealerHand;

    void InitializeGame();
    void DealInitialCards();
    void PlayerAction();
    void DealerAction();
    int HandTotal(const std::vector<Card>& hand) const;
    void DisplayHands() const;
    void AnnounceWinner() const;
};

#endif // BLACKJACKGAME_H
