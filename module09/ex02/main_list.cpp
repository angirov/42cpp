#define DebugList true
#define DebugVec true
#include <iostream>
#include <list>
#include <limits>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <deque>

#define K 10
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
////////////////////////////////////////////////////////////////////
void insertionSort_deque(std::deque<int>& vec, int start, int finish) {
    for (int i = start; i < finish; i++) {
        int tempVal = vec[i + 1];
        int j = i + 1;
        while (j > start && vec[j - 1] > tempVal) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = tempVal;
    }

    // for debugging only
    for (int i=start; i <= finish; ++i) {
        if (DebugVec) std::cout << ">> [" << i << "] " << vec[i] << std::endl;
    }
    if (DebugVec) std::cout << "---------" << std::endl;
}

void merge_deque(std::deque<int>& vec, int s, int m, int e) {
    int lsize = m - s + 1;
    int rsize = e - m;
    std::deque<int> lpart(vec.begin() + s, vec.begin() + m + 1);
    std::deque<int> rpart(vec.begin() + m + 1, vec.begin() + e + 1);
    int li = 0;
    int ri = 0;
    int k = s;

    while (li < lsize && ri < rsize) {
        if (lpart[li] <= rpart[ri])
            vec[k++] = lpart[li++];
        else
            vec[k++] = rpart[ri++];
    }

    while (li < lsize)
        vec[k++] = lpart[li++];

    while (ri < rsize)
        vec[k++] = rpart[ri++];
}

void sort_deque(std::deque<int>& vec, int start, int finish) {
    int middle = (start + finish) / 2;
    if (DebugVec) std::cout << "Vstart:" << start << " Vfinish:" << finish << std::endl;
    if (finish - start >= K) {
        sort_deque(vec, start, middle);
        sort_deque(vec, middle + 1, finish);
        merge_deque(vec, start, middle, finish);
    } else {
        insertionSort_deque(vec, start, finish);
    }
}
////////////////////////////////////////////////////////////////////
void insertionSort(std::vector<int>& vec, int start, int finish) {
    for (int i = start; i < finish; i++) {
        int tempVal = vec[i + 1];
        int j = i + 1;
        while (j > start && vec[j - 1] > tempVal) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = tempVal;
    }

    // for debugging only
    for (int i=start; i <= finish; ++i) {
        if (DebugVec) std::cout << ">> [" << i << "] " << vec[i] << std::endl;
    }
    if (DebugVec) std::cout << "---------" << std::endl;
}

void merge(std::vector<int>& vec, int s, int m, int e) {
    int lsize = m - s + 1;
    int rsize = e - m;
    std::vector<int> lpart(vec.begin() + s, vec.begin() + m + 1);
    std::vector<int> rpart(vec.begin() + m + 1, vec.begin() + e + 1);
    int li = 0;
    int ri = 0;
    int k = s;

    while (li < lsize && ri < rsize) {
        if (lpart[li] <= rpart[ri])
            vec[k++] = lpart[li++];
        else
            vec[k++] = rpart[ri++];
    }

    while (li < lsize)
        vec[k++] = lpart[li++];

    while (ri < rsize)
        vec[k++] = rpart[ri++];
}

void sort(std::vector<int>& vec, int start, int finish) {
    int middle = (start + finish) / 2;
    if (DebugVec) std::cout << "Vstart:" << start << " Vfinish:" << finish << std::endl;
    if (finish - start >= K) {
        sort(vec, start, middle);
        sort(vec, middle + 1, finish);
        merge(vec, start, middle, finish);
    } else {
        insertionSort(vec, start, finish);
    }
}
// ////////////////////////////////////////////////////////////////////
// void insertionSort_list(std::list<int>& A, int start, int finish) {
//     std::list<int>::iterator itStart = A.begin();
//     std::advance(itStart, start);
//     std::list<int>::iterator itFinish = A.begin();
//     std::advance(itFinish, finish + 1);

//     for (std::list<int>::iterator it = itStart; it != itFinish; ++it) {
//         int tempVal = *it;
//         std::list<int>::iterator j = it;
//         while (j != itStart && *(j - 1) > tempVal) {
//             *j = *(j);
//             j--;
//         }
//         *j = tempVal;
//     }

//     for (std::list<int>::iterator it = itStart; it != itFinish; ++it) {
//         if (DebugList) std::cout << ">> [" << std::distance(A.begin(), it) << "] " << *it << std::endl;
//     }
//     if (DebugList) std::cout << "---------" << std::endl;
// }

// void merge_list(std::list<int>& A, int s, int m, int e) {
//     std::list<int> LA;
//     std::list<int> RA;

//     std::list<int>::iterator itA = A.begin();
//     std::advance(itA, s);

//     std::list<int>::iterator itLA = LA.begin();
//     std::list<int>::iterator itRA = RA.begin();

//     for (int i = 0; i < m - s + 1; ++i) {
//         LA.push_back(*itA);
//         ++itA;
//     }

//     for (int i = 0; i < e - m; ++i) {
//         RA.push_back(*itA);
//         ++itA;
//     }

//     itA = A.begin();
//     std::advance(itA, s);

//     itLA = LA.begin();
//     itRA = RA.begin();

//     for (int i = 0; i < e - s + 1; ++i) {
//         if (itRA == RA.end()) {
//             *itA = *itLA;
//             ++itLA;
//         } else if (itLA == LA.end()) {
//             *itA = *itRA;
//             ++itRA;
//         } else if (*itRA > *itLA) {
//             *itA = *itLA;
//             ++itLA;
//         } else {
//             *itA = *itRA;
//             ++itRA;
//         }
//         ++itA;
//     }
// }
//     sort_list(lst, 0, lst.size() - 1);
// void sort_list(std::list<int>& A, int start, int finish) {
//     int middle = (start + finish) / 2;
//     if (DebugList) std::cout << "Lstart:" << start << " Lfinish:" << finish << std::endl;
//     if (finish - start > K) {
//         sort_list(A, start, middle);
//         sort_list(A, middle + 1, finish);
//         merge_list(A, start, middle, finish);
//     } else {
//         insertionSort_list(A, start, finish);
//     }
// }

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
        if (DebugList || DebugVec) std::cout << *it << " ";
    }
    if (DebugList || DebugVec) std::cout << std::endl;

    std::cout << "Before: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;





    std::vector<int> vec(lst.begin(), lst.end());
    std::clock_t start_vec = std::clock();
    sort(vec, 0, vec.size() - 1);
    std::clock_t stop_vec = std::clock();

    // verify vec sort
    if (DebugVec) std::cout << "Verifying the vector sort: ";
    int prev_vec = -1;
    for (int i=0; (unsigned)i < vec.size(); ++i) {
        if (vec[i] < prev_vec)
            exit_msg("Vector Sorting failed: ", 42);
        if (DebugVec) std::cout << vec[i] << " ";
        prev_vec = vec[i];
    }
    if (DebugVec) std::cout << std::endl;





    std::deque<int> deq(lst.begin(), lst.end());
    std::clock_t start_deq = std::clock();
    sort_deque(deq, 0, deq.size() - 1);
    std::clock_t stop_deq = std::clock();
    // verify deq sort
    if (DebugVec) std::cout << "Verifying the deque sort: ";
    int prev_deq = -1;
    for (int i=0; (unsigned)i < deq.size(); ++i) {
        if (deq[i] < prev_deq)
            exit_msg("Vector Sorting failed: ", 42);
        if (DebugVec) std::cout << deq[i] << " ";
        prev_deq = deq[i];
    }
    if (DebugVec) std::cout << std::endl;

    // std::clock_t start_list = std::clock();
    // sort_list(lst, 0, lst.size() - 1);
    // std::clock_t stop_list = std::clock();
    // if (DebugList) std::cout << "============================================== " << std::endl;
    // std::cout << "After: ";
    // int prev = -1;
    // for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    //     std::cout << *it << ", ";
    //     if (*it < prev)
    //         exit_msg("Sorting failed: ", 42);
    //     prev = *it;
    // }
    // std::cout << std::endl;

    std::cout << "Time to process a range of" << vec.size() << "elements with std::vector: " << ((stop_vec - start_vec) * 100000 / CLOCKS_PER_SEC) << "us" << std::endl;
    // std::cout << "Time to process a range of" << lst.size() << "elements with std::list: " << ((stop_list - start_list) * 100000 / CLOCKS_PER_SEC) << "us" << std::endl;
    std::cout << "Time to process a range of" << deq.size() << "elements with std::deque: " << ((stop_deq - start_deq) * 100000 / CLOCKS_PER_SEC) << "us" << std::endl;
}