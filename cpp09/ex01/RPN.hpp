#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

class RPN
{
private:
    std::stack<int> _stack;
    bool isNumber(const std::string &token) const;
    bool isOperator(const std::string &token) const;
    void applyOperator(const std::string &op);
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int PolishAlgorithm(const std::string &input);
};


#endif