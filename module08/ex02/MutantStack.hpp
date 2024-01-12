#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
public:
    MutantStack(void) {
        std::cout << "MutantStack default constructor called" << std::endl;
    };

    MutantStack(const MutantStack &other) : std::stack<T>(other) {
        std::cout << "MutantStack copy constructor called" << std::endl;
    };

    MutantStack & operator=(MutantStack const &other) {
        std::cout << "MutantStack assignment operator called" << std::endl;
        if (other != *this) {
            this->c = other.c;
        }
        return *this;
    };

    ~MutantStack(void) {
        this->c.clear();
    };

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin(void) { return this->c.begin(); };
    iterator end(void) {return this->c.end(); };
};

#endif