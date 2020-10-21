#ifndef __POINT_H
#define __POINT_H

#include <iostream>

namespace Graph_lib {   // our graphics interface
class Point {      // a Point is a pair of ints
    public:
      Point(int x, int y);
      Point(std::istream& ist);
      void save(std::ostream& ost);
      int x() const;
      int y() const;
      bool operator==(Point rhs);
      bool operator!=(Point rhs);
    private:
      int _x;
      int _y;		
};
}
#endif

