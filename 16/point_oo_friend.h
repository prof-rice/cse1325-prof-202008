#ifndef __POINT_H
#define __POINT_H

namespace Graph_lib {   // our graphics interface
class Point {      // a Point is a pair of ints
    public:
      Point(int x, int y);
      friend bool operator==(Point lhs, Point rhs);
    private:
      int _x;
      int _y;
};

bool operator!=(Point lhs, Point rhs);
}
#endif

