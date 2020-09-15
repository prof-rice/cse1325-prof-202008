#include "board.h"
#include <iostream>

int main() {
    int tile, other_tile;
    std::cout << "Number of tiles? ";
    std::cin >> tile;
    Board board{tile};

    int guesses = 0;
    while(!board.solved()) {
        std::cout << board << "\nGuess " << ++guesses << ", select 2 unmatched tiles: ";
        std::cin >> tile >> other_tile;
        std::cout << board.attempt(tile, other_tile) << std::endl;
    }

    std::cout << "\nWINNER after " << guesses << " guesses\n\n"
              << board << std::endl;
}
