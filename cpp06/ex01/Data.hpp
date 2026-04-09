#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data {
    public:
        int         id;
        std::string name;
        std::string type;

        Data();
        Data(int id, std::string name, std::string type);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data();
};

#endif