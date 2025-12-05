#include "PhoneBook.hpp"
#include <iostream> // std::cout, std::cin, std::getline

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof())
            break;

        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContacts();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Unknown command." << std::endl;
    }
    return 0;
}
