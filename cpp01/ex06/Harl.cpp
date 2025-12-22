#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout << BOLD << BLUE << "[ DEBUG ]" << RESET << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << BOLD << GREEN << "[ INFO ]" << RESET << std::endl
              << "I cannot believe adding extra bacon costs more money. "
              << "\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
              << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << BOLD << YELLOW << "[ WARNING ]" << RESET << std::endl
              << "I think I deserve to have some extra bacon for free. "
              << "\nI've been coming for years, whereas you started working here just last month."
              << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << BOLD << RED << "[ ERROR ]" << RESET << std::endl
              << "This is unacceptable! I want to speak to the manager now.\n"
              << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    int i = 0;

    while (i < 4 && levels[i] != level)
        i++;

    switch (i)
    {
        case 0:
            this->debug();
            /* FALLTHROUGH */
        case 1:
            this->info();
            /* FALLTHROUGH */
        case 2:
            this->warning();
            /* FALLTHROUGH */
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
