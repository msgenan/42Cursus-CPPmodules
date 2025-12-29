#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    // Başlangıç değeri (0)
    std::cout << a << std::endl;

    // Pre-increment: Önce artırır (1/256 kadar), sonra yazdırır
    std::cout << ++a << std::endl;

    // Güncel değer
    std::cout << a << std::endl;

    // Post-increment: Önce mevcut değeri yazdırır, sonra artırır
    std::cout << a++ << std::endl;

    // Artırılmış güncel değer
    std::cout << a << std::endl;

    // b nesnesinin değeri (5.05 * 2 = 10.1)
    std::cout << b << std::endl;

    // Statik max fonksiyonu testi
    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}