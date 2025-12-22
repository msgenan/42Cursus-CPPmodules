#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout << BOLD << BLUE << "[ DEBUG ]" << RESET << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << BOLD << GREEN << "[ INFO ]" << RESET << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << BOLD << YELLOW << "[ WARNING ]" << RESET << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << BOLD << RED << "[ ERROR ]" << RESET << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*actions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*actions[i])();
            return;
        }
    }
    std::cout << BOLD << "[ Probably complaining about insignificant things ]" << RESET << std::endl;
}