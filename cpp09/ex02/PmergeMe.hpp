#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <sys/time.h>

class PmergeMe
{
private:
    static bool parsePositiveInt(const std::string &s, int &out);
    static std::vector<size_t> jacobsthalOrder(size_t n);
    
    static void binaryInsertVec(const std::vector<int> &values, std::vector<size_t> &chain, size_t idx);
    static std::vector<size_t> sortIndicesVec(const std::vector<int> &values, std::vector<size_t> indices);
    static std::vector<int> fordJohnsonVector(const std::vector<int> &values);

    static void binaryInsertDeq(const std::deque<int> &values, std::deque<size_t> &chain, size_t idx);
    static std::deque<size_t> sortIndicesDeq(const std::deque<int> &values, std::deque<size_t> indices);
    static std::deque<int> fordJohnsonDeque(const std::deque<int> &values);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run(int argc, char **argv);
};

#endif
