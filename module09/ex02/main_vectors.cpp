#include <iostream>
#include <vector>

#define K 3

template<typename Iterator>
void insertionSort(Iterator start, Iterator finish) {
    for (auto it = std::next(start); it != finish; ++it) {
        auto tempVal = *it;
        auto j = it;
        while (j != start && *(std::prev(j)) > tempVal) {
            *j = *(std::prev(j));
            --j;
        }
        *j = tempVal;
    }

    for (auto it = start; it != std::next(finish); ++it) {
        std::cout << ">> " << *it << std::endl;
    }
    std::cout << "---------" << std::endl;
}

template<typename Iterator>
void merge(Iterator s, Iterator m, Iterator e) {
    using ValueType = typename std::iterator_traits<Iterator>::value_type;

    auto n1 = std::distance(s, m) + 1;
    auto n2 = std::distance(m, e) + 1;

    std::vector<ValueType> LA(s, std::next(m));
    std::vector<ValueType> RA(std::next(m), std::next(e));

    auto itA = s;
    auto itLA = LA.begin();
    auto itRA = RA.begin();

    for (int i = 0; i < n1 + n2 - 2; ++i) {
        if (itRA == RA.end()) {
            *itA = *itLA;
            ++itLA;
        } else if (itLA == LA.end()) {
            *itA = *itRA;
            ++itRA;
        } else if (*itRA > *itLA) {
            *itA = *itLA;
            ++itLA;
        } else {
            *itA = *itRA;
            ++itRA;
        }
        ++itA;
    }
}

template<typename Iterator>
void sort(Iterator Sstart, Iterator Sfinish) {
    auto n = std::distance(Sstart, Sfinish);
    auto Smiddle = std::next(Sstart, n / 2);
    std::cout << "Sstart:" << *Sstart << " Sfinish:" << *(std::prev(Sfinish)) << std::endl;
    if (n > K) {
        sort(Sstart, Smiddle);
        sort(Smiddle, Sfinish);
        merge(Sstart, Smiddle, Sfinish);
    } else {
        insertionSort(Sstart, Sfinish);
    }
}

int main() {
    std::vector<int> A = {2, 5, 1, 6, 7, 3, 8, 4, 9};
    std::cout << "Before: ";
    for (const auto& element : A) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;

    sort(A.begin(), A.end());

    std::cout << "After: ";
    for (const auto& element : A) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}
