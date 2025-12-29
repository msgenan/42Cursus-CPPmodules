#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    // 1. Default Constructor çağrılır. _fixedPointValue = 0 olur.
    Fixed a;

    // 2. Copy Constructor çağrılır. 'a' nesnesi 'b'ye kopyalanır.
    Fixed b( a );

    // 3. Default Constructor çağrılır. 'c' nesnesi oluşturulur.
    Fixed c;

    // 4. Copy Assignment Operator çağrılır. 'b'nin değerleri 'c'ye aktarılır.
    c = b;

    // getRawBits çağrıları ve değerlerin yazdırılması
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
    // Program biterken a, b ve c için Destructor'lar ters sırayla çağrılır.
}