#include <iostream>
#include <vector>
#include "Span.class.hpp"
#include <stdlib.h>
#include <climits>

void printSpan(std::string const &title, Span &span)
{
	std::cout << title << ": "
			<< span.shortestSpan() << ", "
			<< span.longestSpan() << std::endl;
}

int main() {
    Span subject_example = Span(5);
    subject_example.addNumber(6);
    subject_example.addNumber(3);
    subject_example.addNumber(17);
    subject_example.addNumber(9);
    subject_example.addNumber(11);
    printSpan("Test from the subject", subject_example);

    std::cout << "Try add one more (5 + 1 > 5): ";
    try {
    subject_example.addNumber(11);
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Span original(12000);
    try {
    printSpan("Try an empty Span", original);
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::vector<int> vec0;
    srand (time(NULL));
    for (int i=0; i < 10000; ++i) {
        vec0.push_back(rand());
    }
    original.addNumber(vec0.begin(), vec0.end());
    printSpan("Span filled with a range", original);

    Span copy = original;
    copy.addNumber(INT_MAX);
    printSpan("Original Span (same as above)", original);
    printSpan("Copied and extended Span", copy);

    std::vector<int> vec1;
    srand (time(NULL));
    for (int i=0; i < 3000; ++i) {
        vec1.push_back(rand());
    }
    std::cout << "Try add more (10000 + 3000 > 12000): ";
    try {
    original.addNumber(vec1.begin(), vec1.end());
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
