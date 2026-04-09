#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	int random = std::rand() % 3;
	
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& ref)
{
	try
	{
		A& a = dynamic_cast<A&>(ref);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
	}
	
	try
	{
		B& b = dynamic_cast<B&>(ref);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
	}
	
	try
	{
		C& c = dynamic_cast<C&>(ref);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
	}
}
