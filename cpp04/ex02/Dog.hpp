#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
    Brain* brain;

public:
    /* --- Orthodox Canonical Form --- */
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    /* --- Member Functions --- */
    void makeSound() const;
    Brain* getBrain() const;
};

#endif
