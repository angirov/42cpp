#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <algorithm>

template<typename T>
int easyfind(T collection, int el) {
    int result;
    typename T::iterator it = std::find(collection.begin(), collection.end(), el);
    if (it != collection.end()) {
        result = std::distance(collection.begin(), it);
    } else {
        result = -1;
    }
    return result;
}

#endif


// template<typename T>
// int easyfind(T collection, int el) {
//     for (typename T::iterator it = collection.begin(); it != collection.end(); ++it) {
//         if (*it == el) {
//             return std::distance( collection.begin(), it );
//         }
//     }
//     return -1;
// }