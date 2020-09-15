#ifndef _BOARD_H
#define _BOARD_H

#include "tile.h"
#include <vector>

class Board {
  public:
    Board(int tiles);
    std::string attempt(int tile1, int tile2);
    bool solved();
    std::string to_string();
  private:
    std::vector<Tile> _tiles;
};

#endif
