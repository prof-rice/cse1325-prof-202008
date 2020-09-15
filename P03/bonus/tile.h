#ifndef _TILE_H
#define _TILE_H

#include <ostream>

class Tile {
  public:
    Tile(std::string word);
    bool match(Tile& tile);
    std::string word();
    bool matched();
    static int width();
    bool operator==(const Tile& rhs);
    friend std::ostream& operator<<(std::ostream& ost, const Tile& tile);
  private:
    std::string _word;
    bool _matched;
    static int _width;
    static std::string _blank;
};

#endif
