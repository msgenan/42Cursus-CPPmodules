#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = (n << _fractionalBits);
}

Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const {
    return ((float)this->_fixedPointValue / (1 << _fractionalBits));
}

int Fixed::toInt(void) const {
    return (this->_fixedPointValue >> _fractionalBits);
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return o;
}
