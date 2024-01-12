#include <iostream>
#include "MutantStack.hpp"

int main(void) 
{
    MutantStack<int> mstack;
    std::cout << "Pushed 5, 17" << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Poped, so left size: " << mstack.size() << std::endl;

    std::cout << "Pushed 3, 5, 737, 0" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Print out: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    MutantStack<int> s(mstack);
    MutantStack<int>::iterator it1;
    for (it1 = s.begin(); it1 != s.end(); ++it1)
    {
        std::cout << *it1 << " ";
    }
    std::cout << std::endl;

    return 0;
}
