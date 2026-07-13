#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map<std::string, float> _data;

    static std::string trim(const std::string &str);
    static bool isValidDate(const std::string &date);
    static bool parseValue(const std::string &str, float &out);
    float getRate(const std::string &date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void ParseData(const std::string &DataPath);
    void ParseInput(const std::string &InputPath);
};

#endif