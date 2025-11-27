#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     contactCount;
        int     nextContact;

        std::string formatField(const std::string &str) const;

    public:
        PhoneBook();

        void addContact();
        void searchContacts() const;
        void displayContact(int index) const;
};

#endif