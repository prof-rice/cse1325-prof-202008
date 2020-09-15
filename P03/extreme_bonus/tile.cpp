#include "tile.h"

Tile::Tile(std::string word) : _word{word}, _matched{false} {
    if(_width < (int)_word.size()) {
        _width = _word.size();
        _blank = std::string(_width, '-');
    }
}

bool Tile::match(Tile& tile) {
    if(*this == tile) {
        _matched = true;
        tile._matched = true;
    }
    return _matched;
}

std::string Tile::word() {return _word;}
bool Tile::matched() {return _matched;}
int Tile::width() {return _width;}

int Tile::_width = -1;
std::string Tile::_blank;

bool Tile::operator==(const Tile& rhs) {
   return _word == rhs._word;
}
std::ostream& operator<<(std::ostream& ost, const Tile& tile) {
    ost << (tile._matched ? tile._word : Tile::_blank);
    return ost;
}
