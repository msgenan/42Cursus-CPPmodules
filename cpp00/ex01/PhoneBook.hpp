#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

// --- COLOR CODES ---
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

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