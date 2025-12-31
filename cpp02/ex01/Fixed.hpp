#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    /* --- Orthodox Canonical Form --- */
    Fixed();
    Fixed(const Fixed& other);
    Fixed&  operator=(const Fixed& other);
    ~Fixed();

    /* --- Extra Constructors --- */
    Fixed(const int n);
    Fixed(const float n);

    /* --- Conversion Functions --- */
    int     toInt(void) const;
    float   toFloat(void) const;

    /* --- Raw Bit Accessors --- */
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

/* --- Non-member Operator --- */
std::ostream& operator<<(std::ostream& o, Fixed const& i);

#endif