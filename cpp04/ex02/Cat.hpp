#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain* brain;

public:
    /* --- Orthodox Canonical Form --- */
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    /* --- Member Functions --- */
    void makeSound() const;
    Brain* getBrain() const;
};

#endif
