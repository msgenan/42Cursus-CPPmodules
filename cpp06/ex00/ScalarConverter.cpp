#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isPseudo(const std::string& literal)
{
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "-inf" ||
            literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::isChar(const std::string& literal)
{
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string& literal)
{
    if (literal.empty())
        return false;
    
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i = 1;
    
    if (i >= literal.length())
        return false;
    
    for (; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }
    
    // Check for overflow
    char* end;
    long val = std::strtol(literal.c_str(), &end, 10);
    return (val >= std::numeric_limits<int>::min() && 
            val <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.empty() || literal[literal.length() - 1] != 'f')
        return false;
    
    std::string temp = literal.substr(0, literal.length() - 1);
    if (temp.empty())
        return false;
    
    char* end;
    std::strtod(temp.c_str(), &end);
    
    return (*end == '\0');
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    if (literal.empty() || literal[literal.length() - 1] == 'f')
        return false;
    
    char* end;
    std::strtod(literal.c_str(), &end);

    return (*end == '\0');
}

void ScalarConverter::convert(const std::string& literal)
{
    // Handle pseudo-literals (nan, inf)
    if (isPseudo(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        
        if (literal == "nanf" || literal == "nan")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else
        {
            double val;
            if (literal[0] == '-')
                val = -std::numeric_limits<double>::infinity();
            else
                val = std::numeric_limits<double>::infinity();
            
            // Check if it's a float literal (nanf, +inff, -inff) by comparing with known strings
            bool isFloatLiteral = (literal == "nanf" || literal == "+inff" || literal == "-inff");
            
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(val);
            if (isFloatLiteral)
                std::cout << "f";
            std::cout << std::endl;
            std::cout << "double: " << val << std::endl;
        }
        return;
    }

    bool (*checkers[])(const std::string&) = {
        &ScalarConverter::isChar,
        &ScalarConverter::isInt,
        &ScalarConverter::isFloat,
        &ScalarConverter::isDouble
    };

    int typeIndex = -1;
    for (int i = 0; i < 4; i++)
    {
        if (checkers[i](literal))
        {
            typeIndex = i;
            break;
        }
    }

    switch (typeIndex)
    {
        case 0: // Char
        {
            char c = literal[0];
            int i = static_cast<int>(c);
            float f = static_cast<float>(c);
            double d = static_cast<double>(c);
            
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            break;
        }
        case 1: // Int
        {
            char* end;
            long val = std::strtol(literal.c_str(), &end, 10);
            int i = static_cast<int>(val);
            float f = static_cast<float>(val);
            double d = static_cast<double>(val);
            
            // Check char validity: must be in range [0, 255]
            if (val < 0 || val > 255)
                std::cout << "char: impossible" << std::endl;
            else
            {
                char c = static_cast<char>(val);
                if (!std::isprint(c))
                    std::cout << "char: Non displayable" << std::endl;
                else
                    std::cout << "char: '" << c << "'" << std::endl;
            }
            
            std::cout << "int: " << i << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            break;
        }
        case 2: // Float
        {
            double tempd = std::strtod(literal.c_str(), NULL);
            float f = static_cast<float>(tempd);
            int i = static_cast<int>(f);
            double d = static_cast<double>(f);
            
            bool isNaN = (f != f);
            bool isInf = (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max());
            
            if (isNaN || isInf)
                std::cout << "char: impossible" << std::endl;
            else if (f < 0 || f > 255)
                std::cout << "char: impossible" << std::endl;
            else
            {
                char c = static_cast<char>(f);
                if (!std::isprint(c))
                    std::cout << "char: Non displayable" << std::endl;
                else
                    std::cout << "char: '" << c << "'" << std::endl;
            }
            
            if (isNaN || isInf)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << i << std::endl;
            
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            break;
        }
        case 3: // Double
        {
            double d = std::strtod(literal.c_str(), NULL);
            int i = static_cast<int>(d);
            float f = static_cast<float>(d);
            
            bool isNaN = (d != d); 
            bool isInf = (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max());
            
            if (isNaN || isInf)
                std::cout << "char: impossible" << std::endl;
            else if (d < 0 || d > 255)
                std::cout << "char: impossible" << std::endl;
            else
            {
                char c = static_cast<char>(d);
                if (!std::isprint(c))
                    std::cout << "char: Non displayable" << std::endl;
                else
                    std::cout << "char: '" << c << "'" << std::endl;
            }
            
            if (isNaN || isInf)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << i << std::endl;
            
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            break;
        }
        default:
            std::cout << "Error: Invalid literal format." << std::endl;
            break;
    }
}
