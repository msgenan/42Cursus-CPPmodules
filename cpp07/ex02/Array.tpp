#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    _elements = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size) {
    _elements = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _elements[i] = other._elements[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        if (_elements)
            delete[] _elements;
        _size = other._size;
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _elements[i] = other._elements[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    if (_elements)
        delete[] _elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif