#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;

public:
    /* --- Constructors & Destructor --- */
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    Point&  operator=(const Point& other);
    ~Point();

    /* --- Accessors --- */
    Fixed   getX(void) const;
    Fixed   getY(void) const;
};

/* --- BSP Function --- */
bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif
