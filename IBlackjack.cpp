#include <string>
class IBlackjack {
public:
    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~IBlackjack() {}

    // Initialize a new game
    virtual void InitializeGame() = 0;

    // Shuffle the deck of cards
    virtual void ShuffleDeck() = 0;

    // Deal initial cards to the player and dealer
    virtual void DealInitialCards() = 0;

    // Player's action (hit, stand, double down, etc.)
    virtual void PlayerAction(const std::string& action) = 0;

    // Calculate the result of the game and return stats
    virtual void CalculateResult() = 0;

    // Get the current game status (e.g., player's hand, dealer's hand, game result)
    virtual std::string GetGameStatus() const = 0;

    // Return statistics like win/loss ratio, number of games played, etc.
    virtual std::string GetStatistics() const = 0;
};
