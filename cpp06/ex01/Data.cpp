#include "Data.hpp"

Data::Data() : id(0), name("Default"), type("None") {}

Data::Data(int id, std::string name, std::string type) 
    : id(id), name(name), type(type) {}

Data::Data(const Data& other) {
    *this = other;
}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        this->id = other.id;
        this->name = other.name;
        this->type = other.type;
    }
    return *this;
}

Data::~Data() {}
