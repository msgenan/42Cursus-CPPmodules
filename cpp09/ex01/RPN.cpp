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

void RPN::applyOperator(const std::string &token)
{
    int right; // en son push edilen (sağdaki operand)
    int left;  // ondan önce push edilen (soldaki operand)

    right = _stack.top();
    _stack.pop();
    left = _stack.top();
    _stack.pop();

    if (token[0] == '+')
        _stack.push(left + right);
    else if (token[0] == '-')
        _stack.push(left - right);
    else if (token[0] == '*')
        _stack.push(left * right);
    else if (token[0] == '/')
    {
        if (right == 0)
            throw std::runtime_error("Error");
        _stack.push(left / right);
    }
}

bool RPN::isNumber(const std::string &token) const
{
    if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
        return true;
    return false;
}

bool RPN::isOperator(const std::string &token) const
{
    if (token.size() == 1 && (token[0] == '+' || token[0] == '-'
            || token[0] == '*' || token[0] == '/'))
        return true;
    return false;
}