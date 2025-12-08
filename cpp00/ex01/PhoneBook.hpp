#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string> // std::string

class PhoneBook
{
    private:
        Contact contacts[8];
        int     contactCount;
        int     contactIndex;

        int getValidIndex() const;
        std::string formatField(const std::string &str) const;
        std::string getValidInput(const std::string& prompt, const std::string& type);

    public:
        PhoneBook();

        void addContact();
        void searchContacts() const;
        void displayContact(int index) const;
};

#endif