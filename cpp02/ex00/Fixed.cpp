#include "Fixed.hpp"

// 1. Default Constructor
Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// 2. Copy Constructor
// Yeni bir nesne oluşturulurken mevcut bir nesnenin değerlerini kopyalar.
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    // Kendi değerimizi kopyalanacak nesnenin değeriyle eşitliyoruz.
    // Burada doğrudan atama operatörünü çağırarak kod tekrarını önleyebiliriz.
    *this = other; 
}

// 3. Copy Assignment Operator Overload
// Mevcut iki nesne arasındaki atama işlemini (a = b) yönetir.
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    
    // Self-assignment check: Kendimizi kendimize atıyor muyuz? (a = a)
    if (this != &other)
    {
        // Ham bit değerlerini kopyalıyoruz
        this->_fixedPointValue = other.getRawBits();
    }
    
    // Zincirleme atama (a = b = c) için nesnenin kendisini dönüyoruz.
    return *this;
}

// 4. Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Member Functions
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    // setRawBits çağrıldığında mesaj istenmiyor, o yüzden sadece atama yapıyoruz.
    this->_fixedPointValue = raw;
}
