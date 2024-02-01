#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include "easyfind.hpp"

int main () {
    std::list<int> lst;

    lst.push_back(0);
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    lst.push_back(20);

    int tofind = 20;
    int idx = easyfind(lst, tofind);

    if (idx >= 0) {
        std::cout << "The number " << tofind
        << " is found at index " << idx << std::endl;
    } else {
        std::cout << "The number " << tofind
        << " is not found" << std::endl;
    }
}
