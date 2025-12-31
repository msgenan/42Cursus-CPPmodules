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
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        Fixed(const int n);
        Fixed(const float n);

        int     toInt(void) const;
        float   toFloat(void) const;

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif