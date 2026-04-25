#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int N) : _n(N) {}

Span::Span(const Span& other) : _n(other._n), _numbers(other._numbers) {}

Span&  Span::operator=(const Span& other) {
    if (this != &other) {
        this->_n = other._n;
        this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _n)
        throw std::out_of_range("Capacity is full!");
    _numbers.push_back(number);
}

int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::out_of_range("Capacity is below 2!");
return (*std::max_element(_numbers.begin(), _numbers.end()) -
        *std::min_element(_numbers.begin(), _numbers.end()));
}

int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::out_of_range("Capacity is below 2!");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int min_span = sorted[1] - sorted[0];
    for (unsigned int i = 0; i + 1 < sorted.size(); ++i)
    {
        if (sorted[i + 1] - sorted[i] < min_span)
            min_span = sorted[i + 1] - sorted[i];
    }
    return min_span;
}