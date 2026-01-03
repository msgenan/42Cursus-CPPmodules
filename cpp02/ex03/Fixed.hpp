#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

#define RESET  "\033[0m"
#define BOLD   "\033[1m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define BLUE   "\033[34m"
#define CYAN   "\033[36m"

class Fixed
{
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    /* --- Constructors & Destructor --- */
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    /* --- Basic Accessors & Converters --- */
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    /* --- Comparison Operators --- */
    bool    operator>(const Fixed& other) const;
    bool    operator<(const Fixed& other) const;
    bool    operator>=(const Fixed& other) const;
    bool    operator<=(const Fixed& other) const;
    bool    operator==(const Fixed& other) const;
    bool    operator!=(const Fixed& other) const;

    /* --- Arithmetic Operators --- */
    Fixed   operator+(const Fixed& other) const;
    Fixed   operator-(const Fixed& other) const;
    Fixed   operator*(const Fixed& other) const;
    Fixed   operator/(const Fixed& other) const;

    /* --- Increment & Decrement Operators --- */
    Fixed&  operator++(void); // prefix     ++a
    Fixed   operator++(int);  // postfix    a++
    Fixed&  operator--(void); // prefix     --a
    Fixed   operator--(int);  // postfix    a--

    /* --- Static Min & Max Functions --- */
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

/* --- Non-member Operator --- */
std::ostream& operator<<(std::ostream& o, Fixed const& i);

#endif