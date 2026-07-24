#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}
PmergeMe::~PmergeMe() {}

bool PmergeMe::parsePositiveInt(const std::string &s, int &out)
{
    if (s.empty())
        return false;

    for (size_t i = 0; i < s.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }

    errno = 0;
    char *end = NULL;
    long value = std::strtol(s.c_str(), &end, 10);
    if (errno == ERANGE || value > static_cast<long>(INT_MAX))
        return false;

    out = static_cast<int>(value);
    return true;
}

double PmergeMe::elapsedMicroseconds(const struct timeval &start, const struct timeval &end)
{
    return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

std::vector<size_t> PmergeMe::jacobsthalInsertOrder(size_t pendingCount)
{
    std::vector<size_t> order;
    if (pendingCount == 0)
        return order;

    order.push_back(0);

    size_t lastBoundary = 2;
    size_t jacobPrev = 1;
    size_t jacobCurr = 3;

    while (lastBoundary < pendingCount + 1)
    {
        size_t upper = jacobCurr;
        if (upper > pendingCount + 1)
            upper = pendingCount + 1;

        for (size_t v = upper; v > lastBoundary; --v)
        {
            if (v == 2)
                continue;
            order.push_back(v - 2);
        }

        lastBoundary = upper;
        size_t next = jacobCurr + 2 * jacobPrev;
        jacobPrev = jacobCurr;
        jacobCurr = next;
    }
    return order;
}

void PmergeMe::binaryInsertVec(const std::vector<int> &values, std::vector<size_t> &chain, size_t idx)
{
    int val = values[idx];
    size_t lo = 0;
    size_t hi = chain.size();

    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        if (values[chain[mid]] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, idx);
}

std::vector<size_t> PmergeMe::mergeInsertSortVec(const std::vector<int> &values, std::vector<size_t> items)
{
    size_t n = items.size();
    if (n <= 1)
        return items;
    
    bool hasStraggler = (n % 2 == 1);
    size_t straggler = 0;
    if (hasStraggler)
    {
        straggler = items.back();
        items.pop_back();
        n--;
    }

    std::vector<size_t> bigs;
    std::vector<size_t> partnerOf(values.size());
    for (size_t i = 0; i < n; i += 2)
    {
        size_t a = items[i];
        size_t b = items[i + 1];
        if (values[a] < values[b])
            std::swap(a, b);
        bigs.push_back(a);
        partnerOf[a] = b;
    }

    std::vector<size_t> sortedBigs = mergeInsertSortVec(values, bigs);
    std::vector<size_t> chain = sortedBigs;
    chain.insert(chain.begin(), partnerOf[sortedBigs[0]]);

    std::vector<size_t> pending;
    for (size_t i = 1; i < sortedBigs.size(); ++i)
        pending.push_back(partnerOf[sortedBigs[i]]);

    std::vector<size_t> order = jacobsthalInsertOrder(pending.size());
    for (size_t k = 0; k < order.size(); ++k)
        binaryInsertVec(values, chain, pending[order[k]]);

    if (hasStraggler)
        binaryInsertVec(values, chain, straggler);

    return chain;
}

std::vector<int> PmergeMe::sortWithVector(const std::vector<int> &numbers)
{
    std::vector<size_t> items;
    for (size_t i = 0; i < numbers.size(); ++i)
        items.push_back(i);

    std::vector<size_t> sortedItems = mergeInsertSortVec(numbers, items);

    std::vector<int> result;
    for (size_t i = 0; i < sortedItems.size(); ++i)
        result.push_back(numbers[sortedItems[i]]);
    return result;
}

void PmergeMe::binaryInsertDeq(const std::deque<int> &values, std::deque<size_t> &chain, size_t idx)
{
    int val = values[idx];
    size_t lo = 0;
    size_t hi = chain.size();

    while (lo < hi)
    {
        size_t mid = lo + (hi - lo) / 2;
        if (values[chain[mid]] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, idx);
}

std::deque<size_t> PmergeMe::mergeInsertSortDeq(const std::deque<int> &values, std::deque<size_t> items)
{
    size_t n = items.size();
    if (n <= 1)
        return items;

    bool hasStraggler = (n % 2 == 1);
    size_t straggler = 0;
    if (hasStraggler)
    {
        straggler = items.back();
        items.pop_back();
        n--;
    }

    std::deque<size_t> bigs;
    std::vector<size_t> partnerOf(values.size());
    for (size_t i = 0; i < n; i += 2)
    {
        size_t a = items[i];
        size_t b = items[i + 1];
        if (values[a] < values[b])
            std::swap(a, b);
        bigs.push_back(a);
        partnerOf[a] = b;
    }

    std::deque<size_t> sortedBigs = mergeInsertSortDeq(values, bigs);

    std::deque<size_t> chain = sortedBigs;
    chain.insert(chain.begin(), partnerOf[sortedBigs[0]]);

    std::deque<size_t> pending;
    for (size_t i = 1; i < sortedBigs.size(); ++i)
        pending.push_back(partnerOf[sortedBigs[i]]);

    std::vector<size_t> order = jacobsthalInsertOrder(pending.size());
    for (size_t k = 0; k < order.size(); ++k)
        binaryInsertDeq(values, chain, pending[order[k]]);

    if (hasStraggler)
        binaryInsertDeq(values, chain, straggler);

    return chain;
}

std::deque<int> PmergeMe::sortWithDeque(const std::deque<int> &numbers)
{
    std::deque<size_t> items;
    for (size_t i = 0; i < numbers.size(); ++i)
        items.push_back(i);

    std::deque<size_t> sortedItems = mergeInsertSortDeq(numbers, items);

    std::deque<int> result;
    for (size_t i = 0; i < sortedItems.size(); ++i)
        result.push_back(numbers[sortedItems[i]]);
    return result;
}

void PmergeMe::run(int argc, char **argv)
{
    if (argc < 2)
        throw std::runtime_error("Error");

    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i)
    {
        int value;
        if (!parsePositiveInt(argv[i], value))
            throw std::runtime_error("Error");
        numbers.push_back(value);
    }

    std::cout << "Before:";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << " " << numbers[i];
    std::cout << std::endl;

    std::vector<int> vecInput(numbers.begin(), numbers.end());
    std::deque<int> deqInput(numbers.begin(), numbers.end());

    struct timeval start, end;

    gettimeofday(&start, NULL);
    std::vector<int> sortedVec = sortWithVector(vecInput);
    gettimeofday(&end, NULL);
    double vecTime = elapsedMicroseconds(start, end);

    gettimeofday(&start, NULL);
    std::deque<int> sortedDeq = sortWithDeque(deqInput);
    gettimeofday(&end, NULL);
    double deqTime = elapsedMicroseconds(start, end);
    (void)sortedDeq;

    std::cout << "After:";
    for (size_t i = 0; i < sortedVec.size(); ++i)
        std::cout << " " << sortedVec[i];
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << numbers.size()
               << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size()
               << " elements with std::deque : " << deqTime << " us" << std::endl;
}
