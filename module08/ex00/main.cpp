#include <vector>
#include <list>
#include <iostream>
#include <iterator>

template<typename T>
int easyfind(T collection, int el) {
    for (typename T::iterator it = collection.begin(); it != collection.end(); ++it) {
        if (*it == el) {
            return std::distance( collection.begin(), it );
        }
    }
    return -1;
}

int main () {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    int tofind = 10;
    int idx = easyfind(lst, tofind);

    if (idx >= 0) {
        std::cout << "The number " << tofind
        << " is found at index " << idx << std::endl;
    } else {
        std::cout << "The number " << tofind
        << " is not found" << std::endl;
    }
}
