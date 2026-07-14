#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) : _stack(other._stack) {}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}
RPN::~RPN() {}

int RPN::PolishAlgorithm(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (isNumber(token))
            _stack.push(atoi(token.c_str()));
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");
            applyOperator(token);
        }
        else
            throw std::runtime_error("Error");
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    return _stack.top();
}

