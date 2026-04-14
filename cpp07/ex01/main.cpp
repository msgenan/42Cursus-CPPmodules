#include "iter.hpp"

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

template <typename T>
void printElement(T const & x) {
    std::cout << x << " ";
}

void increment(int & n) {
    n++;
}

void toUpper(std::string & str) {
    for (size_t i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
}

void multiplyByTwo(int & n) {
    n *= 2;
}

template <typename T>
void printFormatted(T const & x) {
    std::cout << CYAN << x << RESET << " ";
}

int main() {
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║      Iter Template Function        ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // Test 1: Print integer array
    std::cout << BOLD << YELLOW << "▶ Test 1: Print Integer Array" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        int intArray[] = {1, 2, 3, 4, 5};
        size_t intLen = 5;
        
        std::cout << GREEN << "Original array: " << RESET;
        ::iter(intArray, intLen, printElement<int>);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Increment integers
    std::cout << BOLD << YELLOW << "▶ Test 2: Increment Integer Array" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        int intArray[] = {1, 2, 3, 4, 5};
        size_t intLen = 5;
        
        std::cout << GREEN << "Before increment: " << RESET;
        ::iter(intArray, intLen, printElement<int>);
        std::cout << std::endl;
        
        ::iter(intArray, intLen, increment);
        
        std::cout << GREEN << "After increment:  " << RESET;
        ::iter(intArray, intLen, printElement<int>);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Multiply integers by 2
    std::cout << BOLD << YELLOW << "▶ Test 3: Multiply Integer Array by 2" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        int intArray[] = {1, 2, 3, 4, 5};
        size_t intLen = 5;
        
        std::cout << GREEN << "Before multiplication: " << RESET;
        ::iter(intArray, intLen, printElement<int>);
        std::cout << std::endl;
        
        ::iter(intArray, intLen, multiplyByTwo);
        
        std::cout << GREEN << "After multiplication:  " << RESET;
        ::iter(intArray, intLen, printElement<int>);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Print string array
    std::cout << BOLD << YELLOW << "▶ Test 4: Print String Array" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        std::string strArray[] = {"Hello", "42", "Istanbul", "C++"};
        size_t strLen = 4;
        
        std::cout << GREEN << "Original array: " << RESET;
        ::iter(strArray, strLen, printElement<std::string>);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Convert strings to uppercase
    std::cout << BOLD << YELLOW << "▶ Test 5: Convert Strings to Uppercase" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        std::string strArray[] = {"hello", "world", "cpp", "template"};
        size_t strLen = 4;
        
        std::cout << GREEN << "Before uppercase: " << RESET;
        ::iter(strArray, strLen, printElement<std::string>);
        std::cout << std::endl;
        
        ::iter(strArray, strLen, toUpper);
        
        std::cout << GREEN << "After uppercase:  " << RESET;
        ::iter(strArray, strLen, printElement<std::string>);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Print const integer array
    std::cout << BOLD << YELLOW << "▶ Test 6: Print Const Integer Array" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        const int constArray[] = {10, 20, 30, 40, 50};
        
        std::cout << GREEN << "Const array: " << RESET;
        ::iter(constArray, 5, printElement<int>);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test 7: Print double array
    std::cout << BOLD << YELLOW << "▶ Test 7: Print Double Array" << RESET << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    {
        double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
        
        std::cout << GREEN << "Double array: " << RESET;
        ::iter(doubleArray, 5, printElement<double>);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << GREEN << "║        All Tests Complete          ║" << RESET << std::endl;
    std::cout << BOLD << GREEN << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
