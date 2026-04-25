#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
private:
    unsigned int _n;
    std::vector<int> _numbers;
public:
    Span(unsigned int N);
    Span(const Span& other);
    Span&  operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();

    template <typename T>
    void addMultipleNumbers(T begin, T end) {
        if (_numbers.size() + std::distance(begin, end) > _n)
            throw std::out_of_range("error: Out of range!");
        _numbers.insert(_numbers.end(), begin, end);
    }
};

#endif