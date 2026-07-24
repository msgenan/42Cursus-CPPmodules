#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <iomanip>
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
    static bool   parsePositiveInt(const std::string &s, int &out);
    static double elapsedMicroseconds(const struct timeval &start, const struct timeval &end);
    static std::vector<size_t> jacobsthalInsertOrder(size_t pendingCount);

    // --- std::vector ile merge-insertion sort ---
    static void binaryInsertVec(const std::vector<int> &values, std::vector<size_t> &chain, size_t idx);
    static std::vector<size_t> mergeInsertSortVec(const std::vector<int> &values, std::vector<size_t> items);
    static std::vector<int> sortWithVector(const std::vector<int> &numbers);

    // --- std::deque ile merge-insertion sort ---
    static void binaryInsertDeq(const std::deque<int> &values, std::deque<size_t> &chain, size_t idx);
    static std::deque<size_t> mergeInsertSortDeq(const std::deque<int> &values, std::deque<size_t> items);
    static std::deque<int> sortWithDeque(const std::deque<int> &numbers);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run(int argc, char **argv);
};

#endif
