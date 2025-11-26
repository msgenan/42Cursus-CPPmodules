#include "contact.hpp"

void Contact::setFirstName(const std::string &str)
{
    this->firstname = str;
}
void Contact::setLastName(const std::string &str)
{
    this->lastname = str;
}

void Contact::setNickname(const std::string &str)
{
    this->nickname = str;
}

void Contact::setPhoneNumber(const std::string &str)
{
    this->phonenumber = str;
}
void Contact::setDarkestSecret(const std::string &str)
{
    this->darkestsecret = str;
}

std::string Contact::getFirstName() const
{
    return this->firstname;
}

std::string Contact::getLastName() const
{
    return this->lastname;
}

std::string Contact::getNickname() const
{
    return this->nickname;
}

std::string Contact::getPhoneNumber() const
{
    return this->phonenumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->darkestsecret;
}
