#include "PmergeMe.hpp"

int main(int argc, char** argv) {

    //process input
    if (argc < 2)
        exit_msg("ERROR: wrong number of arguments.", 10);
    std::list<int> lst = process_input(argc, argv);
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (DEBUG) std::cout << *it << " ";
    }
    if (DEBUG) std::cout << std::endl;

    std::cout << "Before: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;


    // create vector
    std::vector<int> vec(lst.begin(), lst.end());
    // sort vector
    std::clock_t start_vec = std::clock();
    sort(vec, 0, vec.size() - 1);
    std::clock_t stop_vec = std::clock();
    // verify vec sort
    if (DEBUG) std::cout << "Verifying the vector sort: ";
    int prev_vec = -1;
    for (int i=0; (unsigned)i < vec.size(); ++i) {
        if (vec[i] < prev_vec)
            exit_msg("Vector Sorting failed: ", 42);
        if (DEBUG) std::cout << vec[i] << " ";
        prev_vec = vec[i];
    }
    if (DEBUG) std::cout << std::endl;


    // create deque
    std::deque<int> deq(lst.begin(), lst.end());
    // sort deque
    std::clock_t start_deq = std::clock();
    sort_deque(deq, 0, deq.size() - 1);
    std::clock_t stop_deq = std::clock();
    // verify deq sort
    if (DEBUG) std::cout << "Verifying the deque sort: ";
    int prev_deq = -1;
    for (int i=0; (unsigned)i < deq.size(); ++i) {
        if (deq[i] < prev_deq)
            exit_msg("Deque Sorting failed: ", 42);
        if (DEBUG) std::cout << deq[i] << " ";
        prev_deq = deq[i];
    }
    if (DEBUG) std::cout << std::endl;


    // print timings
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << ((stop_vec - start_vec) * 100000 / CLOCKS_PER_SEC) << "us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << ((stop_deq - start_deq) * 100000 / CLOCKS_PER_SEC) << "us" << std::endl;
}
