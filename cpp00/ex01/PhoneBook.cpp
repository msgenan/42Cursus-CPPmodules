#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook()
{
    contactIndex = 0;
    contactCount = 0;
}

void PhoneBook::addContact()
{
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    contacts[contactIndex].setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contacts[contactIndex].setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    contacts[contactIndex].setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contacts[contactIndex].setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    contacts[contactIndex].setDarkestSecret(input);

    if (contactCount < 8)
        contactCount++;

    contactIndex = (contactIndex + 1) % 8;
}

void PhoneBook::searchContacts() const
{
    if (contactCount == 0)
    {
        std::cout << "No contacts saved." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index"      << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name"  << "|"
              << std::setw(10) << "Nickname"   << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName())  << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname())  << std::endl;
    }

    int index = getValidIndex();
    if (index == -1)
        return;

    displayContact(index);
}

void PhoneBook::displayContact(int index) const
{
    std::cout << "First name: "     << contacts[index].getFirstName()     << std::endl;
    std::cout << "Last name: "      << contacts[index].getLastName()      << std::endl;
    std::cout << "Nickname: "       << contacts[index].getNickname()      << std::endl;
    std::cout << "Phone number: "   << contacts[index].getPhoneNumber()   << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::formatField(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

int PhoneBook::getValidIndex() const
{
    std::string input;
    std::cout << "Enter index to display: ";
    std::getline(std::cin, input);

    if (input.length() != 1 || !isdigit(input[0]))
    {
        std::cout << "Invalid index." << std::endl;
        return -1;
    }

    int index = input[0] - '0';
    if (index < 0 || index >= contactCount)
    {
        std::cout << "Invalid index." << std::endl;
        return -1;
    }
    return index;
}

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
