#include <iostream>
#include <list>

#define K 3

void insertionSort(std::list<int>& A, int start, int finish) {
    auto itStart = std::next(A.begin(), start);
    auto itFinish = std::next(itStart, finish - start + 1);

    for (auto it = std::next(itStart); it != itFinish; ++it) {
        int tempVal = *it;
        auto j = it;
        while (j != itStart && *(std::prev(j)) > tempVal) {
            *j = *(std::prev(j));
            --j;
        }
        *j = tempVal;
    }

    for (auto it = itStart; it != std::next(itFinish); ++it) {
        std::cout << ">> [" << std::distance(A.begin(), it) << "] " << *it << std::endl;
    }
    std::cout << "---------" << std::endl;
}

void merge(std::list<int>& A, int s, int m, int e) {
    int n1 = m - s + 1;
    int n2 = e - m;

    std::list<int> LA(std::next(A.begin(), s), std::next(A.begin(), m + 1));
    std::list<int> RA(std::next(A.begin(), m + 1), std::next(A.begin(), e + 1));

    auto itA = std::next(A.begin(), s);

    auto itLA = LA.begin();
    auto itRA = RA.begin();

    for (int i = 0; i < e - s + 1; ++i) {
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

void sort(std::list<int>& A, int Sstart, int Sfinish) {
    int Smiddle = (Sstart + Sfinish) / 2;
    std::cout << "Sstart:" << Sstart << " Sfinish:" << Sfinish << std::endl;
    if (Sfinish - Sstart > K) {
        sort(A, Sstart, Smiddle);
        sort(A, Smiddle + 1, Sfinish);
        merge(A, Sstart, Smiddle, Sfinish);
    } else {
        insertionSort(A, Sstart, Sfinish);
    }
}

int main() {
    std::list<int> A = {2, 5, 1, 6, 7, 3, 8, 4, 9};
    std::cout << "Before: ";
    for (const auto& element : A) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;

    sort(A, 0, A.size() - 1);

    std::cout << "After: ";
    for (const auto& element : A) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}
