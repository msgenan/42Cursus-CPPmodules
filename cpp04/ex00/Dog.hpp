#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    /* --- Orthodox Canonical Form --- */
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    /* --- Member Functions --- */
    void makeSound() const;
};

#endif
