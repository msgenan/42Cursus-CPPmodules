#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();                                 // Default
    Point(const float x, const float y);     // Float
    Point(const Point& other);              // Copy
    Point& operator=(const Point& other);   // Assignment
    ~Point();                               // Destructor

    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif