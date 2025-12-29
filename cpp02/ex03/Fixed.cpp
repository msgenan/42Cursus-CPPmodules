#include "Fixed.hpp"

// --- OCF & Constructors ---
Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {}

Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) { *this = other; }

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

// --- Karşılaştırma Operatörleri ---
bool Fixed::operator>(const Fixed& other) const { return this->_fixedPointValue > other.getRawBits(); }
bool Fixed::operator<(const Fixed& other) const { return this->_fixedPointValue < other.getRawBits(); }
bool Fixed::operator>=(const Fixed& other) const { return this->_fixedPointValue >= other.getRawBits(); }
bool Fixed::operator<=(const Fixed& other) const { return this->_fixedPointValue <= other.getRawBits(); }
bool Fixed::operator==(const Fixed& other) const { return this->_fixedPointValue == other.getRawBits(); }
bool Fixed::operator!=(const Fixed& other) const { return this->_fixedPointValue != other.getRawBits(); }

// --- Aritmetik Operatörler ---
// Not: Çarpma ve bölmede float dönüşümü yaparak hassasiyet kaybını ve taşmayı önlüyoruz.
Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const { return Fixed(this->toFloat() / other.toFloat()); }

// --- Artırma/Azaltma Operatörleri ---

// Prefix (++a): Değeri en küçük birim kadar artırır ve nesnenin kendisini döner.
Fixed& Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

// Postfix (a++): Değeri artırır ama eski halini döner.
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

// --- Statik Fonksiyonlar (Min/Max) ---
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

// --- Member Functions ---
int Fixed::getRawBits(void) const { return this->_fixedPointValue; }
void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }
float Fixed::toFloat(void) const { return (float)this->_fixedPointValue / (1 << _fractionalBits); }
int Fixed::toInt(void) const { return this->_fixedPointValue >> _fractionalBits; }

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return o;
}