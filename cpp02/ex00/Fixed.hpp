#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

    /* --- Raw Bit Accessors --- */
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif