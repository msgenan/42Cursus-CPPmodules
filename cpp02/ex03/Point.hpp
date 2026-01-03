#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

#define RESET  "\033[0m"
#define BOLD   "\033[1m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define BLUE   "\033[34m"
#define CYAN   "\033[36m"

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
