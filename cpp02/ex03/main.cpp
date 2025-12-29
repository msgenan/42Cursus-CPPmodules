#include <iostream>
#include "Point.hpp"

int main() {
    Point const a(0, 0);
    Point const b(10, 0);
    Point const c(0, 10);
    
    // Test 1: Tam ortada bir nokta (True bekliyoruz)
    Point const p1(2, 2);
    if (bsp(a, b, c, p1))
        std::cout << "P1 is inside the triangle" << std::endl;
    else
        std::cout << "P1 is outside the triangle" << std::endl;

    // Test 2: Tam kenar üzerinde bir nokta (False bekliyoruz)
    Point const p2(5, 0);
    if (bsp(a, b, c, p2))
        std::cout << "P2 is inside" << std::endl;
    else
        std::cout << "P2 is outside (on edge)" << std::endl;

    // Test 3: Dışarıda bir nokta (False bekliyoruz)
    Point const p3(12, 12);
    if (bsp(a, b, c, p3))
        std::cout << "P3 is inside" << std::endl;
    else
        std::cout << "P3 is outside" << std::endl;

    return 0;
}
