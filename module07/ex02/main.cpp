#include <iostream>
#include "Array.class.hpp"
# include <cstdlib> // for rand
#include <string> 

#define MAX_VAL 10
int main(int, char**)
{
    {
        std::cout << "=============== Default construction ================" << std::endl;
        Array<std::string> defaultStrings;
        Array<int> defaultSumbers;
    }

    std::cout << "=============== N-size construction ================" << std::endl;
    Array<std::string> strings(MAX_VAL);
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
        strings[i] = "string";
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
        
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    {
        std::cout << "=============== Copy constructor ================" << std::endl;
        Array<std::string> moreStrings = strings;
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "==================================================" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
            moreStrings[i] = "new string";
            std::cout << "Orig array:\t" << numbers[i] << "\tCopy array:\t" << test[i] << std::endl;
        }
        std::cout << "==================================================" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << "Orig string:\t" << strings[i] << "\tCopy string:\t" << moreStrings[i] << std::endl;
        }
    }

    delete [] mirror;//
    return 0;
}