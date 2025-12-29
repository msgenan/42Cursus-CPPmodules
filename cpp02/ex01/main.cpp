#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    // 1. Default constructor ile a = 0.0 oluşturulur
    Fixed a;

    // 2. Int constructor ile b = 10.0 (raw: 10 << 8 = 2560) oluşturulur
    Fixed const b( 10 );

    // 3. Float constructor ile c = 42.42 oluşturulur (raw: roundf(42.42 * 256))
    Fixed const c( 42.42f );

    // 4. Copy constructor ile d, b'nin kopyası olarak oluşturulur
    Fixed const d( b );

    // 5. Geçici bir Fixed nesnesi (float) oluşturulur, a'ya atanır ve geçici olan yok edilir
    a = Fixed( 1234.4321f );

    // operator<< aşırı yüklemesi sayesinde nesneleri doğrudan yazdırıyoruz
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    // toInt() fonksiyonu ile ondalık kısmı atıp ham integer'a dönüyoruz
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}