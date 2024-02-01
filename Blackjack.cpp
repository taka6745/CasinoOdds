#include "BlackjackGame.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

// Card implementation
int Card::GetValue() const {
    if (rank >= Rank::TEN) return 10;
    if (rank == Rank::ACE) return 11;
    return static_cast<int>(rank);
}

// Deck implementation
Deck::Deck() {
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 2; rank <= 14; ++rank) {
            cards.emplace_back(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
        }
    }
}

void Deck::Shuffle() {
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(static_cast<unsigned int>(time(nullptr))));
}

Card Deck::DealCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}

// BlackjackGame implementation
void BlackjackGame::InitializeGame() {
    deck.Shuffle();
    playerHand.clear();
    dealerHand.clear();
}

void BlackjackGame::DealInitialCards() {
    playerHand.push_back(deck.DealCard());
    playerHand.push_back(deck.DealCard());
    dealerHand.push_back(deck.DealCard());
    dealerHand.push_back(deck.DealCard());
}

void BlackjackGame::PlayerAction() {
    std::string action;
    while (true) {
        std::cout << "Your hand: ";
        DisplayHands();

        if (HandTotal(playerHand) >= 21) break;

        std::cout << "Hit or Stand? (h/s): ";
        std::cin >> action;
        if (action == "h") {
            playerHand.push_back(deck.DealCard());
        } else if (action == "s") {
            break;
        }
    }
}

void BlackjackGame::DealerAction() {
    while (HandTotal(dealerHand) < 17) {
        dealerHand.push_back(deck.DealCard());
    }
}

int BlackjackGame::HandTotal(const std::vector<Card>& hand) const {
    int total = 0;
    int aces = 0;
    for (const auto& card : hand) {
        total += card.GetValue();
        if (card.GetValue() == 11) aces += 1;
    }
    while (total > 21 && aces > 0) {
        total -= 10;
        aces -= 1;
    }
    return total;
}

void BlackjackGame::DisplayHands() const {
    for (const auto& card : playerHand) {
        std::cout << card.GetValue() << " ";
    }
    std::cout << "(Total: " << HandTotal(playerHand) << ")\n";
}

void BlackjackGame::AnnounceWinner() const {
    int playerTotal = HandTotal(playerHand);
    int dealerTotal = HandTotal(dealerHand);

    std::cout << "Dealer's hand: ";
    for (const auto& card : dealerHand) {
        std::cout << card.GetValue() << " ";
    }
    std::cout << "(Total: " << dealerTotal << ")\n";

    if (playerTotal > 21) {
        std::cout << "You bust! Dealer wins.\n";
    } else if (dealerTotal > 21 || playerTotal > dealerTotal) {
        std::cout << "You win!\n";
    } else if (playerTotal < dealerTotal) {
        std::cout << "Dealer wins.\n";
    } else {
        std::cout << "It's a tie!\n";
    }
}

void BlackjackGame::Play() {
    InitializeGame();
    DealInitialCards();
    PlayerAction();
    if (HandTotal(playerHand) <= 21) {
        DealerAction();
    }
    AnnounceWinner();
}
