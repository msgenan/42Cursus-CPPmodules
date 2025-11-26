#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact 
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestsecret;

    public:
        void setFirstName(const std::string &str);
        void setLastName(const std::string &str);
        void setNickname(const std::string &str);
        void setPhoneNumber(const std::string &str);
        void setDarkestSecret(const std::string &str);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif