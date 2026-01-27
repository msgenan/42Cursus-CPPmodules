#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string type;

public:
    /* --- Orthodox Canonical Form --- */
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    /* --- Member Functions --- */
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif
