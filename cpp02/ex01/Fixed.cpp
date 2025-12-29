#include "Fixed.hpp"

// --- OCF Bölümü ---

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

// --- Yeni Kurucular (Dönüşüm Başlıyor) ---

// Tam sayıyı 8 bit sola kaydırarak fixed-point yaparız. (n * 2^8)
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = (n << _fractionalBits);
}

// Float değerini 2^8 (256) ile çarpıp en yakın tam sayıya yuvarlarız.
Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

// --- Dönüşüm Fonksiyonları ---

// Ham değeri 2^8'e bölerek float elde ederiz.
float Fixed::toFloat(void) const {
    return ((float)this->_fixedPointValue / (1 << _fractionalBits));
}

// Ham değeri 8 bit sağa kaydırarak ondalığı atar ve integer elde ederiz.
int Fixed::toInt(void) const {
    return (this->_fixedPointValue >> _fractionalBits);
}

// --- Raw Bits (Ex00'dan) ---

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// --- Sınıf Dışı: Operatör Overload ---

// std::cout << a dediğimizde burası çalışır.
std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return o;
}