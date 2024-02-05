#define DEGUG false
#include <iostream>
#include <list>
#include <limits>
#include <ctime>
#include <stdlib.h>

#define K 2
void exit_msg(std::string msg, int n) {
    std::cerr << "\nPmergeMe: " << msg << std::endl;
    exit(n);
}

bool is_int(long n) {
    int imin = std::numeric_limits<int>::min();
    int imax = std::numeric_limits<int>::max();

    return (n <= imax && n >= imin);
}


bool is_int_literal(std::string str)
{
    int len = str.length();
    char c;

    for (int i = 0; i < len; i++)
    {
        c = str[i];
        if (isdigit(c))
            continue;
        else
            return (false);
    }
    return (true);
}

#include <iostream>
#include <list>
#include <iterator>

// ...

void insertionSort(std::list<int>& A, int start, int finish) {
    std::list<int>::iterator itStart = A.begin();
    std::advance(itStart, start);
    std::list<int>::iterator itFinish = A.begin();
    std::advance(itFinish, finish + 1);

    for (std::list<int>::iterator it = itStart; it != itFinish; ++it) {
        int tempVal = *it;
        std::list<int>::iterator j = it;
        while (j != itStart && *(--j) > tempVal) {
            *j = *(j);
            --j;
        }
        *j = tempVal;
    }

    for (std::list<int>::iterator it = itStart; it != itFinish; ++it) {
        std::cout << ">> [" << std::distance(A.begin(), it) << "] " << *it << std::endl;
    }
    std::cout << "---------" << std::endl;
}

void merge(std::list<int>& A, int s, int m, int e) {
    std::list<int> LA;
    std::list<int> RA;

    std::list<int>::iterator itA = A.begin();
    std::advance(itA, s);

    std::list<int>::iterator itLA = LA.begin();
    std::list<int>::iterator itRA = RA.begin();

    for (int i = 0; i < m - s + 1; ++i) {
        LA.push_back(*itA);
        ++itA;
    }

    for (int i = 0; i < e - m; ++i) {
        RA.push_back(*itA);
        ++itA;
    }

    itA = A.begin();
    std::advance(itA, s);

    itLA = LA.begin();
    itRA = RA.begin();

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

void sort_list(std::list<int>& A, int Sstart, int Sfinish) {
    int Smiddle = (Sstart + Sfinish) / 2;
    std::cout << "Sstart:" << Sstart << " Sfinish:" << Sfinish << std::endl;
    if (Sfinish - Sstart > K) {
        sort_list(A, Sstart, Smiddle);
        sort_list(A, Smiddle + 1, Sfinish);
        merge(A, Sstart, Smiddle, Sfinish);
    } else {
        insertionSort(A, Sstart, Sfinish);
    }
}

// int main() {
//     std::list<int> A = {2, 5, 1, 6, 7, 3, 8, 4, 9};
//     std::cout << "Before: ";
//     for (const auto& element : A) {
//         std::cout << element << ", ";
//     }
//     std::cout << std::endl;

//     sort_list(A, 0, A.size() - 1);

//     std::cout << "After: ";
//     for (const auto& element : A) {
//         std::cout << element << ", ";
//     }
//     std::cout << std::endl;
// }

std::list<int> process_input(int argc, char **argv) {
    std::list<int> collector;

    for (int i=1; i<argc; ++i) {
        std::string word(argv[i]);
        if (is_int_literal(word)) {
            long n = atol(word.c_str());
            if (n == 0 && word != "0")
                exit_msg("Bad input: Only ingeter numbers allowed: " + word, 1);
            if (n < 0)
                exit_msg("Bad input: Only positive numbers allowed: " + word, 1);
            if (!is_int(n))
                exit_msg("One of the input numbers is beyond integer limits: " + word, 6);
            collector.push_back(n);
        } else {
            exit_msg("Bad input: " + word, 20);
        }
    }
    return collector;
}

int main(int argc, char** argv) {
    if (argc < 2)
        exit_msg("ERROR: wrong number of arguments.", 10);
    std::list<int> lst = process_input(argc, argv);
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (DEGUG) std::cout << *it << " ";
    }
    if (DEGUG) std::cout << std::endl;
    // std::vector<int> vec(lst.begin(), lst.end());
    // std::cout << "Before: ";
    // for (int i=0; (unsigned)i < lst.size(); ++i) {
    //     std::cout << vec[i] << ", ";
    // }
    // std::cout << std::endl;
    std::cout << "Before: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    std::clock_t start_vec = std::clock();
    sort_list(lst, 0, lst.size() - 1);
    std::clock_t stop_vec = std::clock();

    std::cout << "\n============================================== " << std::endl;
    std::cout << "After: ";
    int prev = -1;
    // for (int i=0; (unsigned)i < lst.size(); ++i) {
    //     if (vec[i] < prev)
    //         exit_msg("Sorting failed: ", 42);
    //     std::cout << vec[i] << ", ";
    //     prev = vec[i];
    // }
    // std::cout << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << ", ";
        if (*it < prev)
            exit_msg("Sorting failed: ", 42);
    }
    std::cout << std::endl;

    std::cout << ((stop_vec - start_vec) * 100000 / CLOCKS_PER_SEC) << "us" << std::endl;
}