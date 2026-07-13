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

void BitcoinExchange::ParseData(const std::string &DataPath)
{
    std::ifstream file(DataPath.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }

    std::string line;
    std::getline(file, line); //first line (header)

    while (std::getline(file, line))
    {
        size_t pos = line.find(','); //find returns size_t
        if (pos != std::string::npos)
        {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            std::stringstream ss_num(value);
            float f_num;
            ss_num >> f_num;
            _data.insert(std::make_pair(key, f_num));
        }
    }
    file.close();
}

std::string BitcoinExchange::trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    int maxDay = (month == 2 && leap) ? 29 : daysInMonth[month - 1];

    return day <= maxDay;
}

bool BitcoinExchange::parseValue(const std::string &str, float &out)
{
    if (str.empty())
        return false;

    std::stringstream ss(str);
    ss >> out;
    if (ss.fail())
        return false;

    std::string leftover;
    ss >> leftover;
    return leftover.empty(); // reject trailing garbage e.g. "12abc"
}

float BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);

    if (it != _data.end() && it->first == date)
        return it->second;
    if (it == _data.begin())
        return 0.0f; // no earlier date exists in the database
    --it;
    return it->second;
}

void BitcoinExchange::ParseInput(const std::string &InputPath)
{
    std::ifstream file(InputPath.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }

    std::string line;
    std::getline(file, line); // header line "date | value"

    while (std::getline(file, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value;
        if (!parseValue(valueStr, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = getRate(date);
        std::cout << date << " => " << valueStr << " = " << value * rate << std::endl;
    }
    file.close();
}
