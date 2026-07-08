#include "Span.hpp"
#include <iostream>

// Color codes
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║         Span Container Class       ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // ===== SUBJECT TEST =====
    std::cout << BOLD << YELLOW << "▶ Test 1: Subject Test (from PDF)" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << CYAN << "Numbers added: " << RESET << "6, 3, 17, 9, 11" << std::endl;
        std::cout << GREEN << "Shortest Span: " << RESET << sp.shortestSpan() << std::endl;
        std::cout << GREEN << "Longest Span: " << RESET << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl;

    // ===== TEST 2: Exception - Less than 2 elements =====
    std::cout << BOLD << YELLOW << "▶ Test 2: Exception with < 2 elements" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try {
            Span sp1 = Span(5);
            sp1.addNumber(5);
            std::cout << CYAN << "Attempting to find span with only 1 element..." << RESET << std::endl;
            sp1.shortestSpan();
        } catch (const std::out_of_range& e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // ===== TEST 3: Exception - Capacity full =====
    std::cout << BOLD << YELLOW << "▶ Test 3: Exception when Capacity Full" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try {
            Span sp2 = Span(2);
            sp2.addNumber(1);
            sp2.addNumber(2);
            std::cout << CYAN << "Span capacity: 2 (already filled)" << RESET << std::endl;
            std::cout << CYAN << "Attempting to add 3rd number..." << RESET << std::endl;
            sp2.addNumber(3);
        } catch (const std::out_of_range& e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // ===== TEST 4: 10,000 numbers via addMultipleNumbers =====
    std::cout << BOLD << YELLOW << "▶ Test 4: 10,000 Numbers (addMultipleNumbers)" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        const unsigned int SIZE = 10000;
        std::vector<int> numbers;
        numbers.reserve(SIZE);
        for (unsigned int i = 0; i < SIZE; ++i)
            numbers.push_back(i);

        Span sp3 = Span(SIZE);
        sp3.addMultipleNumbers(numbers.begin(), numbers.end());

        std::cout << CYAN << "Numbers added: " << RESET << SIZE << " numbers (0 .. " << SIZE - 1 << ")" << std::endl;
        std::cout << GREEN << "Shortest Span: " << RESET << sp3.shortestSpan() << std::endl;
        std::cout << GREEN << "Longest Span: " << RESET << sp3.longestSpan() << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << GREEN << "║        All Tests Complete          ║" << RESET << std::endl;
    std::cout << BOLD << GREEN << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
