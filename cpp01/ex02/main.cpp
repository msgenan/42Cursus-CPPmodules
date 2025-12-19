#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << CYAN << "\n=== Memory Addresses ===" << RESET << std::endl;
    std::cout << YELLOW << "str address:        " << RESET << &str << std::endl;
    std::cout << YELLOW << "stringPTR holds:    " << RESET << stringPTR << std::endl;
    std::cout << YELLOW << "stringREF address:  " << RESET << &stringREF << std::endl;

    std::cout << CYAN << "\n=== Values ===" << RESET << std::endl;
    std::cout << GREEN << "str value:          " << RESET << str << std::endl;
    std::cout << GREEN << "stringPTR points:   " << RESET << *stringPTR << std::endl;
    std::cout << GREEN << "stringREF value:    " << RESET << stringREF << std::endl;

    return 0;
}
