#include "easyfind.hpp"
#include <list>
#include <vector>

int main()
{
    std::vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);

    std::list<int> list;
    list.push_back(2);
    list.push_back(3);
    list.push_front(1);

    try {
        std::cout <<  *easyfind(vector, 2) << std::endl ;
        std::cout <<  *easyfind(vector, 4) << std::endl ;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout <<  *easyfind(list, 3) << std::endl ;
        std::cout <<  *easyfind(list, 4) << std::endl ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}
