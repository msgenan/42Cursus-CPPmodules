#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::ParseData()
{
    std::string path = "data.csv";
    std::ifstream file(path.c_str());

    if (!file.is_open())
    {
        std::cout << "error: file cannot open!";
        return ;
    }
    
    std::string line;
    std::getline(file, line); //first line
    
    while(std::getline(file, line))
    {
        size_t pos = line.find(','); //find returns size_t
        if (pos != std::string::npos)
        {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            // (pos + 1) print the complete sub-string followed by the given character.
            std::stringstream ss_num(value);
            float f_num;
            ss_num >> f_num;
            _data.insert(std::make_pair(key, f_num));
        }
    }
    file.close();
}

// TEMPORARY DEBUG - remove before submission
void BitcoinExchange::PrintData() const
{
    for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); ++it)
        std::cout << it->first << " -> " << it->second << std::endl;
    std::cout << "total entries: " << _data.size() << std::endl;
}
