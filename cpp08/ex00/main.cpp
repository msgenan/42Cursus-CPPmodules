#include "easyfind.hpp"
#include <list>
#include <vector>
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
    std::cout << BOLD << BLUE << "║       Easy Find Template Test      ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // ===== TEST 1: Vector - Element Found =====
    std::cout << BOLD << YELLOW << "▶ Test 1: Vector - Element Found" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        std::vector<int> vector;
        vector.push_back(1);
        vector.push_back(2);
        vector.push_back(3);
        std::cout << CYAN << "Vector contents: " << RESET << "1, 2, 3" << std::endl;
        
        try {
            std::cout << GREEN << "Searching for 2... Found: " << RESET << *easyfind(vector, 2) << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // ===== TEST 2: Vector - Element Not Found =====
    std::cout << BOLD << YELLOW << "▶ Test 2: Vector - Element Not Found" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        std::vector<int> vector;
        vector.push_back(1);
        vector.push_back(2);
        vector.push_back(3);
        std::cout << CYAN << "Vector contents: " << RESET << "1, 2, 3" << std::endl;
        
        try {
            std::cout << CYAN << "Searching for 4..." << RESET << std::endl;
            *easyfind(vector, 4);
        }
        catch (const std::exception &e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // ===== TEST 3: List - Element Found =====
    std::cout << BOLD << YELLOW << "▶ Test 3: List - Element Found" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        std::list<int> list;
        list.push_back(2);
        list.push_back(3);
        list.push_front(1);
        std::cout << CYAN << "List contents: " << RESET << "1, 2, 3" << std::endl;
        
        try {
            std::cout << GREEN << "Searching for 3... Found: " << RESET << *easyfind(list, 3) << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // ===== TEST 4: List - Element Not Found =====
    std::cout << BOLD << YELLOW << "▶ Test 4: List - Element Not Found" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        std::list<int> list;
        list.push_back(2);
        list.push_back(3);
        list.push_front(1);
        std::cout << CYAN << "List contents: " << RESET << "1, 2, 3" << std::endl;
        
        try {
            std::cout << CYAN << "Searching for 4..." << RESET << std::endl;
            *easyfind(list, 4);
        }
        catch (const std::exception &e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // ===== TEST 5: Vector with Multiple Occurrences =====
    std::cout << BOLD << YELLOW << "▶ Test 5: Vector - First Occurrence Found" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        std::vector<int> vector;
        vector.push_back(5);
        vector.push_back(10);
        vector.push_back(5);
        vector.push_back(15);
        vector.push_back(5);
        std::cout << CYAN << "Vector contents: " << RESET << "5, 10, 5, 15, 5" << std::endl;
        
        try {
            std::cout << GREEN << "Searching for 5... Found at position" << RESET << std::endl;
            std::cout << MAGENTA << "Note: Returns first occurrence" << RESET << std::endl;
            *easyfind(vector, 5);
        }
        catch (const std::exception &e) {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // ===== TEST 6: Empty Vector =====
    std::cout << BOLD << YELLOW << "▶ Test 6: Empty Vector" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        std::vector<int> vector;
        std::cout << CYAN << "Vector contents: " << RESET << "(empty)" << std::endl;
        
        try {
            std::cout << CYAN << "Searching for 1..." << RESET << std::endl;
            *easyfind(vector, 1);
        }
        catch (const std::exception &e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // ===== TEST 7: Large Vector =====
    std::cout << BOLD << YELLOW << "▶ Test 7: Large Vector - Element Found" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        std::vector<int> vector;
        for (int i = 0; i < 1000; i++)
            vector.push_back(i);
        
        std::cout << CYAN << "Vector size: " << RESET << "1000 elements (0-999)" << std::endl;
        
        try {
            std::cout << GREEN << "Searching for 500... Found: " << RESET << *easyfind(vector, 500) << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    // ===== TEST 8: List with Negative Numbers =====
    std::cout << BOLD << YELLOW << "▶ Test 8: List - Negative Numbers" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        std::list<int> list;
        list.push_back(-5);
        list.push_back(0);
        list.push_back(5);
        std::cout << CYAN << "List contents: " << RESET << "-5, 0, 5" << std::endl;
        
        try {
            std::cout << GREEN << "Searching for -5... Found: " << RESET << *easyfind(list, -5) << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << GREEN << "║        All Tests Complete          ║" << RESET << std::endl;
    std::cout << BOLD << GREEN << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
