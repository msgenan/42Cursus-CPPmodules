#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class BitcoinExchange
{
private:
    std::map<std::string, float> _data;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void ParseData();
    void PrintData() const; // TEMPORARY DEBUG - remove before submission
};

#endif