#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define DEBUG true
# include <iostream>
# include <list>
# include <limits>
# include <ctime>
# include <stdlib.h>
# include <vector>
# include <deque>

# define K 10
void exit_msg(std::string msg, int n);
bool is_int_literal(std::string str);
void insertionSort_deque(std::deque<int>& vec, int start, int finish);
void merge_deque(std::deque<int>& vec, int s, int m, int e);
void sort_deque(std::deque<int>& vec, int start, int finish);
void insertionSort(std::vector<int>& vec, int start, int finish);
void merge(std::vector<int>& vec, int s, int m, int e);
void sort(std::vector<int>& vec, int start, int finish);
std::list<int> process_input(int argc, char **argv);

#endif