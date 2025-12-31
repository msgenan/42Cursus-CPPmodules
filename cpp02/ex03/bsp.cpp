#include "Point.hpp"

static Fixed abs(Fixed n) {
    return (n < 0) ? (n * -1) : n;
}

static Fixed calculateArea(Point const a, Point const b, Point const c) {
    Fixed area = (a.getX() * (b.getY() - c.getY()) +
                  b.getX() * (c.getY() - a.getY()) +
                  c.getX() * (a.getY() - b.getY())) / 2;
    return abs(area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed abcArea = calculateArea(a, b, c);
    Fixed pabArea = calculateArea(point, a, b);
    Fixed pbcArea = calculateArea(point, b, c);
    Fixed pacArea = calculateArea(point, a, c);

    if (pabArea == 0 || pbcArea == 0 || pacArea == 0)
        return false;

    return (pabArea + pbcArea + pacArea == abcArea);
}
