#include "Base.hpp"
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& ref);

// Color codes
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define CYAN        "\033[36m"

int main(void)
{
	std::cout << std::endl;
	std::cout << BOLD << BLUE << "╔════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << BLUE << "║           Identify Real Type Test Suite        ║" << RESET << std::endl;
	std::cout << BOLD << BLUE << "╚════════════════════════════════════════════════╝" << RESET << std::endl;
	std::cout << std::endl;

	// Test 1: Pointer identification
	std::cout << BOLD << YELLOW << "▶ Test 1: Identify using Pointer (10 iterations)" << RESET << std::endl;
	std::cout << std::string(50, '-') << std::endl;
	{
		for (int i = 0; i < 10; i++)
		{
			Base* ptr = generate();
			std::cout << "Generated: ";
			identify(ptr);
			delete ptr;
		}
		std::cout << GREEN << "✓ Pointer identification test completed!" << RESET << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Reference identification
	std::cout << BOLD << YELLOW << "▶ Test 2: Identify using Reference (10 iterations)" << RESET << std::endl;
	std::cout << std::string(50, '-') << std::endl;
	{
		for (int i = 0; i < 10; i++)
		{
			Base* ptr = generate();
			std::cout << "Generated: ";
			identify(*ptr);
			delete ptr;
		}
		std::cout << GREEN << "✓ Reference identification test completed!" << RESET << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Mixed pointer and reference
	std::cout << BOLD << YELLOW << "▶ Test 3: Mixed Pointer/Reference Test" << RESET << std::endl;
	std::cout << std::string(50, '-') << std::endl;
	{
		for (int i = 0; i < 5; i++)
		{
			Base* ptr = generate();
			
			std::cout << "  Iteration " << (i + 1) << ":" << std::endl;
			std::cout << "    - Pointer:   ";
			identify(ptr);
			std::cout << "    - Reference: ";
			identify(*ptr);
			
			delete ptr;
		}
		std::cout << GREEN << "✓ Mixed identification test completed!" << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << BOLD << GREEN << "╔════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << GREEN << "║            All Tests Complete! ✓               ║" << RESET << std::endl;
	std::cout << BOLD << GREEN << "╚════════════════════════════════════════════════╝" << RESET << std::endl;
	std::cout << std::endl;

	return 0;
}
