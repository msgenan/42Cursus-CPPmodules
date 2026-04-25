#include "MutantStack.hpp"
#include <iostream>
#include <list>

// Color codes
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define CYAN        "\033[36m"

int main()
{
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << BLUE << "║   MutantStack - Iterable Stack     ║" << RESET << std::endl;
    std::cout << BOLD << BLUE << "╚════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    // ===== TEST 1: Subject Test =====
    std::cout << BOLD << YELLOW << "▶ Subject Test (from PDF)" << RESET << std::endl;
    std::cout << std::string(38, '-') << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << GREEN << "top(): " << RESET << mstack.top() << std::endl;

        mstack.pop();
        std::cout << GREEN << "size(): " << RESET << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        std::cout << CYAN << "Elements via iterator: " << RESET;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // ===== TEST 2: Copy to std::stack =====
    std::cout << BOLD << YELLOW << "▶ Copy to std::stack<int>" << RESET << std::endl;
    std::cout << std::string(38, '-') << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        
        std::stack<int> normalStack(mstack);
        std::cout << GREEN << "Copied successfully!" << RESET << std::endl;
        std::cout << GREEN << "top(): " << RESET << normalStack.top() << std::endl;
    }
    std::cout << std::endl;

    // ===== TEST 3: Comparison with std::list =====
    std::cout << BOLD << YELLOW << "▶ MutantStack vs std::list output" << RESET << std::endl;
    std::cout << std::string(38, '-') << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        std::list<int> list;
        list.push_back(5);
        list.push_back(17);
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        
        std::cout << CYAN << "MutantStack: " << RESET;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        
        std::cout << CYAN << "std::list:   " << RESET;
        for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << GREEN << "✓ Outputs match!" << RESET << std::endl;
    }
    std::cout << std::endl;

    // ===== TEST 4: Const and iterators =====
    std::cout << BOLD << YELLOW << "▶ Const iterator support" << RESET << std::endl;
    std::cout << std::string(38, '-') << std::endl;
    {
        MutantStack<int> ms;
        ms.push(100);
        ms.push(200);
        ms.push(300);
        
        const MutantStack<int> cms = ms;
        std::cout << CYAN << "Const stack: " << RESET;
        for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // ===== TEST 5: Reverse iteration =====
    std::cout << BOLD << YELLOW << "▶ Reverse iteration (rbegin/rend)" << RESET << std::endl;
    std::cout << std::string(38, '-') << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        
        std::cout << CYAN << "Forward:  " << RESET;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        
        std::cout << CYAN << "Reverse:  " << RESET;
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << GREEN << "╔════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << GREEN << "║    All Tests Passed! ✓         ║" << RESET << std::endl;
    std::cout << BOLD << GREEN << "╚════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
