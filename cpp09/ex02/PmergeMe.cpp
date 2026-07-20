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

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
    std::vector<size_t> order;
    if (n == 0)
        return order;

    order.push_back(0);

    size_t prevBoundary = 2;
    size_t jPrev = 1;
    size_t jCurr = 3;

    while (prevBoundary < n + 1)
    {
        size_t upper = jCurr;
        if (upper > n + 1)
            upper = n + 1;

        for (size_t v = upper; v > prevBoundary; --v)
        {
            if (v == 2)
                continue;
            order.push_back(v - 2);
        }

        prevBoundary = upper;
        size_t next = jCurr + 2 * jPrev;
        jPrev = jCurr;
        jCurr = next;
    }

    return order;
}

// vector version
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

std::vector<size_t> PmergeMe::sortIndicesVec(const std::vector<int> &values, std::vector<size_t> indices)
{
    size_t n = indices.size();
    if (n <= 1)
        return indices;

    bool hasStraggler = (n % 2 == 1);
    size_t stragglerIdx = 0;
    if (hasStraggler)
    {
        stragglerIdx = indices.back();
        indices.pop_back();
        n--;
    }

    std::vector<size_t> largerIdx;
    std::vector<size_t> smallerIdx;
    for (size_t i = 0; i < n; i += 2)
    {
        size_t idxA = indices[i];
        size_t idxB = indices[i + 1];
        if (values[idxA] < values[idxB])
            std::swap(idxA, idxB);
        largerIdx.push_back(idxA);
        smallerIdx.push_back(idxB);
    }

    std::vector<size_t> sortedLarger = sortIndicesVec(values, largerIdx);
    std::vector<size_t> posInPairs(values.size());

    for (size_t i = 0; i < largerIdx.size(); ++i)
        posInPairs[largerIdx[i]] = i;

    std::vector<size_t> chain;
    chain.push_back(smallerIdx[posInPairs[sortedLarger[0]]]);

    for (size_t i = 0; i < sortedLarger.size(); ++i)
        chain.push_back(sortedLarger[i]);

    std::vector<size_t> pending;
    for (size_t i = 1; i < sortedLarger.size(); ++i)
        pending.push_back(smallerIdx[posInPairs[sortedLarger[i]]]);

    std::vector<size_t> order = jacobsthalOrder(pending.size());
    for (size_t k = 0; k < order.size(); ++k)
        binaryInsertVec(values, chain, pending[order[k]]);

    if (hasStraggler)
        binaryInsertVec(values, chain, stragglerIdx);

    return chain;
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &values)
{
    std::vector<size_t> indices;
    indices.reserve(values.size());
    for (size_t i = 0; i < values.size(); ++i)
        indices.push_back(i);

    std::vector<size_t> sortedIdx = sortIndicesVec(values, indices);

    std::vector<int> result;
    result.reserve(values.size());
    for (size_t i = 0; i < sortedIdx.size(); ++i)
        result.push_back(values[sortedIdx[i]]);

    return result;
}

