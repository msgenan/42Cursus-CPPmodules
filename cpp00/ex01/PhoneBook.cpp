#include "PhoneBook.hpp"

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
