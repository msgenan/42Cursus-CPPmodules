#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <iterator>

class ValueNotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Error: Missing value!";
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw ValueNotFoundException();
    }
    return it;
}

#endif