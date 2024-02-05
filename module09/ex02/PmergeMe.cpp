#define DEBUG true
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
        if (DEBUG) std::cout << ">> [" << i << "] " << vec[i] << std::endl;
    }
    if (DEBUG) std::cout << "---------" << std::endl;
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
    if (DEBUG) std::cout << "Vstart:" << start << " Vfinish:" << finish << std::endl;
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
        if (DEBUG) std::cout << ">> [" << i << "] " << vec[i] << std::endl;
    }
    if (DEBUG) std::cout << "---------" << std::endl;
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
    if (DEBUG) std::cout << "Vstart:" << start << " Vfinish:" << finish << std::endl;
    if (finish - start >= K) {
        sort(vec, start, middle);
        sort(vec, middle + 1, finish);
        merge(vec, start, middle, finish);
    } else {
        insertionSort(vec, start, finish);
    }
}

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
