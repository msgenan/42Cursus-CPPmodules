#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        // 1. Default Constructor
        Fixed();

        // 2. Copy Constructor
        Fixed(const Fixed& other);

        // 3. Copy Assignment Operator Overload
        Fixed& operator=(const Fixed& other);

        // 4. Destructor
        ~Fixed();

        // Member Functions
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif