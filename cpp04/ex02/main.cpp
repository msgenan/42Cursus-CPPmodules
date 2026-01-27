#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;

    const int arraySize = 4;
    AAnimal* animals[arraySize];

    for (int idx = 0; idx < arraySize / 2; idx++)
    {
        animals[idx] = new Dog();
    }
    for (int idx = arraySize / 2; idx < arraySize; idx++)
    {
        animals[idx] = new Cat();
    }

    for (int idx = 0; idx < arraySize; idx++)
    {
        delete animals[idx];
    }

    Dog basic;
    {
        Dog tmp = basic;
    }

    return 0;
}
