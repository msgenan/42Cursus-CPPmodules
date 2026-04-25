#include "Span.hpp"
#include <iostream>

// Color codes
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

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

    // ===== TEST 3: Exactly 2 elements =====
    std::cout << BOLD << YELLOW << "▶ Test 3: Exactly 2 Elements" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Span sp2 = Span(2);
        sp2.addNumber(10);
        sp2.addNumber(20);
        std::cout << CYAN << "Numbers added: " << RESET << "10, 20" << std::endl;
        std::cout << GREEN << "Shortest Span: " << RESET << sp2.shortestSpan() << std::endl;
        std::cout << GREEN << "Longest Span: " << RESET << sp2.longestSpan() << std::endl;
        std::cout << MAGENTA << "Note: Both spans are equal (only 1 span possible)" << RESET << std::endl;
    }
    std::cout << std::endl;

    // ===== TEST 4: Negative numbers =====
    std::cout << BOLD << YELLOW << "▶ Test 4: Negative and Mixed Numbers" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Span sp3 = Span(5);
        sp3.addNumber(-10);
        sp3.addNumber(-5);
        sp3.addNumber(0);
        sp3.addNumber(5);
        sp3.addNumber(10);
        std::cout << CYAN << "Numbers added: " << RESET << "-10, -5, 0, 5, 10" << std::endl;
        std::cout << GREEN << "Shortest Span: " << RESET << sp3.shortestSpan() << std::endl;
        std::cout << GREEN << "Longest Span: " << RESET << sp3.longestSpan() << std::endl;
        std::cout << MAGENTA << "Note: Range from -10 to 10 = 20" << RESET << std::endl;
    }
    std::cout << std::endl;

    // ===== TEST 5: Exception - Capacity full =====
    std::cout << BOLD << YELLOW << "▶ Test 5: Exception when Capacity Full" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        try {
            Span sp4 = Span(2);
            sp4.addNumber(1);
            sp4.addNumber(2);
            std::cout << CYAN << "Span capacity: 2 (already filled)" << RESET << std::endl;
            std::cout << CYAN << "Attempting to add 3rd number..." << RESET << std::endl;
            sp4.addNumber(3);
        } catch (const std::out_of_range& e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // ===== TEST 6: Duplicate numbers =====
    std::cout << BOLD << YELLOW << "▶ Test 6: Duplicate Numbers" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Span sp6 = Span(5);
        sp6.addNumber(5);
        sp6.addNumber(5);
        sp6.addNumber(5);
        sp6.addNumber(5);
        sp6.addNumber(5);
        std::cout << CYAN << "Numbers added: " << RESET << "5, 5, 5, 5, 5" << std::endl;
        std::cout << GREEN << "Shortest Span: " << RESET << sp6.shortestSpan() << std::endl;
        std::cout << GREEN << "Longest Span: " << RESET << sp6.longestSpan() << std::endl;
        std::cout << MAGENTA << "Note: All spans = 0 (identical numbers)" << RESET << std::endl;
    }
    std::cout << std::endl;

    // ===== TEST 7: Large range =====
    std::cout << BOLD << YELLOW << "▶ Test 7: Large Range of Numbers" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Span sp7 = Span(5);
        sp7.addNumber(1);
        sp7.addNumber(100);
        sp7.addNumber(500);
        sp7.addNumber(999);
        sp7.addNumber(50);
        std::cout << CYAN << "Numbers added: " << RESET << "1, 100, 500, 999, 50" << std::endl;
        std::cout << GREEN << "Shortest Span: " << RESET << sp7.shortestSpan() << std::endl;
        std::cout << GREEN << "Longest Span: " << RESET << sp7.longestSpan() << std::endl;
        std::cout << MAGENTA << "Note: Longest = 999 - 1 = 998" << RESET << std::endl;
    }
    std::cout << std::endl;

    // ===== TEST 8: Unsorted input =====
    std::cout << BOLD << YELLOW << "▶ Test 8: Unsorted Input Order" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        Span sp8 = Span(6);
        sp8.addNumber(42);
        sp8.addNumber(7);
        sp8.addNumber(88);
        sp8.addNumber(1);
        sp8.addNumber(99);
        sp8.addNumber(15);
        std::cout << CYAN << "Numbers added (random order): " << RESET << "42, 7, 88, 1, 99, 15" << std::endl;
        std::cout << GREEN << "Shortest Span: " << RESET << sp8.shortestSpan() << std::endl;
        std::cout << GREEN << "Longest Span: " << RESET << sp8.longestSpan() << std::endl;
        std::cout << MAGENTA << "Note: Algorithm sorts internally for calculation" << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << GREEN << "║        All Tests Complete          ║" << RESET << std::endl;
    std::cout << BOLD << GREEN << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}