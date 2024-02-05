#define DEGUG false

#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <stdlib.h>
#include <ctime>
#define K 14

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
        if (DEGUG) std::cout << ">> [" << i << "] " << vec[i] << std::endl;
    }
    if (DEGUG) std::cout << "---------" << std::endl;
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
    int Smiddle = (start + finish) / 2;
    if (DEGUG) std::cout << "start:" << start << " finish:" << finish << std::endl;
    if (finish - start >= K) {
        sort(vec, start, Smiddle);
        sort(vec, Smiddle + 1, finish);
        merge(vec, start, Smiddle, finish);
    } else {
        insertionSort(vec, start, finish);
    }
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
void exit_msg(std::string msg, int n) {
    std::cerr << "\nPmergeMe: " << msg << std::endl;
    exit(n);
}

bool is_int(long n) {
    int imin = std::numeric_limits<int>::min();
    int imax = std::numeric_limits<int>::max();

    return (n <= imax && n >= imin);
}


std::string::iterator skip_whitespace(std::string::iterator &start, std::string::iterator &end) {
    while (std::isspace(*start) && start != end) {
    start++;
    }
    return start;
}

std::string get_next_word(std::string::iterator &it, std::string::iterator &end) {
    skip_whitespace(it, end);
    std::string::iterator start = it;
    while (!std::isspace(*it) && it != end) {
        it++;
    }
    std::string result = std::string(start, it);
    return result;
};

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
    std::vector<int> vec(lst.begin(), lst.end());
    std::cout << "Before: ";
    for (int i=0; (unsigned)i < vec.size(); ++i) {
        std::cout << vec[i] << ", ";
    }
    std::cout << std::endl;

    std::clock_t start_vec = std::clock();
    sort(vec, 0, vec.size() - 1);
    std::clock_t stop_vec = std::clock();

    std::cout << "\n============================================== " << std::endl;
    std::cout << "After: ";
    int prev = -1;
    for (int i=0; (unsigned)i < vec.size(); ++i) {
        if (vec[i] < prev)
            exit_msg("Sorting failed: ", 42);
        std::cout << vec[i] << ", ";
        prev = vec[i];
    }
    std::cout << std::endl;

    std::cout << ((stop_vec - start_vec) * 100000 / CLOCKS_PER_SEC) << "us" << std::endl;
}
