#include "BlackjackGame.h"
#include <iostream>

int main() {
    BlackjackGame game;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        game.Play();
        
        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
        std::cout << "\n";
    }

    std::cout << "Thanks for playing!\n";

    return 0;
}
