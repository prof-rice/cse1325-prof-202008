#ifndef _TILE_H
#define _TILE_H

#include <string>

class Tile {
  public:
    Tile(std::string word);
    bool match(Tile& tile);
    std::string to_string();
    std::string word();
    bool matched();
    static int width();
  private:
    std::string _word;
    bool _matched;
    static int _width;
    static std::string _blank;
};

#endif
