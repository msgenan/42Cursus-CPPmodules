#include <iostream>
#include "Point.hpp"

static void printResult(const std::string& name, float x, float y, bool inside) {
    std::cout << "  " << CYAN << "●" << RESET << " Point " 
              << BOLD << name << RESET << " (" << x << ", " << y << ") → ";
    
    if (inside)
        std::cout << GREEN << "✓ INSIDE" << RESET << std::endl;
    else
        std::cout << RED << "✗ OUTSIDE" << RESET << std::endl;
}

int main() {
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
    std::cout << BOLD << "         BINARY SPACE PARTITIONING TEST        " << RESET << std::endl;
    std::cout << BOLD << BLUE << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
    std::cout << std::endl;

    // Triangle vertices
    Point const a(0, 0);
    Point const b(10, 0);
    Point const c(0, 10);

    std::cout << YELLOW << "▲ Triangle vertices:" << RESET << std::endl;
    std::cout << "  A(0, 0)  B(10, 0)  C(0, 10)" << std::endl;
    std::cout << std::endl;

    // Test 1: Point inside triangle
    std::cout << BOLD << "Test 1: Point Inside Triangle" << RESET << std::endl;
    Point const p1(2, 2);
    printResult("P1", 2, 2, bsp(a, b, c, p1));
    std::cout << std::endl;

    // Test 2: Point on edge
    std::cout << BOLD << "Test 2: Point On Edge" << RESET << std::endl;
    Point const p2(5, 0);
    printResult("P2", 5, 0, bsp(a, b, c, p2));
    std::cout << std::endl;

    // Test 3: Point outside triangle
    std::cout << BOLD << "Test 3: Point Outside Triangle" << RESET << std::endl;
    Point const p3(12, 12);
    printResult("P3", 12, 12, bsp(a, b, c, p3));
    std::cout << std::endl;

    // Test 4: Point at vertex
    std::cout << BOLD << "Test 4: Point At Vertex" << RESET << std::endl;
    Point const p4(0, 0);
    printResult("P4", 0, 0, bsp(a, b, c, p4));
    std::cout << std::endl;

    // Test 5: Another inside point
    std::cout << BOLD << "Test 5: Another Inside Point" << RESET << std::endl;
    Point const p5(3, 3);
    printResult("P5", 3, 3, bsp(a, b, c, p5));
    std::cout << std::endl;

    // Test 6: Edge case - close to edge
    std::cout << BOLD << "Test 6: Very Close To Edge" << RESET << std::endl;
    Point const p6(4.9f, 0.1f);
    printResult("P6", 4.9f, 0.1f, bsp(a, b, c, p6));
    std::cout << std::endl;

    std::cout << BOLD << BLUE << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
