#include "Fixed.hpp"

/* --- Constructors & Destructor --- */

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {}

Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed::~Fixed() {}

/* --- Assignment Operator --- */

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _fixedPointValue = other.getRawBits();
    }
    return *this;
}

/* --- Comparison Operators --- */

bool Fixed::operator>(const Fixed& other)  const { return _fixedPointValue >  other.getRawBits(); }
bool Fixed::operator<(const Fixed& other)  const { return _fixedPointValue <  other.getRawBits(); }
bool Fixed::operator>=(const Fixed& other) const { return _fixedPointValue >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed& other) const { return _fixedPointValue <= other.getRawBits(); }
bool Fixed::operator==(const Fixed& other) const { return _fixedPointValue == other.getRawBits(); }
bool Fixed::operator!=(const Fixed& other) const { return _fixedPointValue != other.getRawBits(); }

/* --- Arithmetic Operators --- */

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const { return Fixed(toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const { return Fixed(toFloat() / other.toFloat()); }

/* --- Increment / Decrement Operators --- */

Fixed& Fixed::operator++(void) {
    _fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--(void) {
    _fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _fixedPointValue--;
    return temp;
}

/* --- Static Min / Max Functions --- */

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

/* --- Member Functions --- */

int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

/* --- Non-member Operators --- */

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return o;
}