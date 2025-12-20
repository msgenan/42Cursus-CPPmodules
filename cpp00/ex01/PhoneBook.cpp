#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook()
{
    contactIndex = 0;
    contactCount = 0;
}

void PhoneBook::addContact()
{
    Contact& currentContact = contacts[contactIndex];

    std::cout << GREEN << "--- Adding New Contact ---" << RESET << std::endl;

    std::string fn = getValidInput("Enter first name: ", "ANY");
    if (fn.empty()) return;
    currentContact.setFirstName(fn);

    std::string ln = getValidInput("Enter last name: ", "ANY");
    if (ln.empty()) return;
    currentContact.setLastName(ln);

    std::string nn = getValidInput("Enter nickname: ", "ANY");
    if (nn.empty()) return;
    currentContact.setNickname(nn);

    std::string pn = getValidInput("Enter phone number: ", "NUMERIC");
    if (pn.empty()) return;
    currentContact.setPhoneNumber(pn);

    std::string ds = getValidInput("Enter darkest secret: ", "ANY");
    if (ds.empty()) return;
    currentContact.setDarkestSecret(ds);

    if (contactCount < 8)
        contactCount++;
    contactIndex = (contactIndex + 1) % 8;
}

void PhoneBook::searchContacts() const
{
    if (contactCount == 0)
    {
        std::cout << RED << "No contacts saved." << std::endl;
        return;
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << GREEN << std::setw(10) << "Index"      << RESET << "|"
              << GREEN << std::setw(10) << "First Name" << RESET << "|"
              << GREEN << std::setw(10) << "Last Name"  << RESET << "|"
              << GREEN << std::setw(10) << "Nickname"   << RESET << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << RED << std::setw(10) << i << RESET <<"|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName())  << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname())  << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
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

std::string PhoneBook::getValidInput(const std::string& prompt, const std::string& type)
{
    std::string input;
    bool valid;

    while (true)
    {
        std::cout << BOLD << prompt << RESET;
        if (!std::getline(std::cin, input))
            return std::string();

        if (input.empty())
        {
            std::cout << RED << "error: " << RESET << "Field cannot be empty." << std::endl;
            continue;
        }

        valid = true;
        if (type == "NUMERIC")
        {
            for (size_t i = 0; i < input.length(); i++)
            {
                if (!std::isdigit(input[i]))
                {
                    valid = false;
                    std::cout << RED << "error: " << RESET << "Invalid input. Please enter digits only." << std::endl;
                    break;
                }
            }
        }

        if (valid)
            return input;
    }
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
        std::cout << RED << "error: " << RESET << "Invalid index." << std::endl;
        return -1;
    }

    int index = input[0] - '0';
    if (index < 0 || index >= contactCount)
    {
        std::cout << RED << "error: " << RESET << "Invalid index." << std::endl;
        return -1;
    }
    return index;
}
