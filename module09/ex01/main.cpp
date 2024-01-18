#include <iostream>
#include <string>
#include <stdlib.h>
#include "rpn.hpp"

int main(int argc, char** argv) {

    if (argc > 2 || argc <= 1)
        return 1; 
    std::string input = argv[1];

    Rpn rpn = Rpn(input);
    rpn.run();
    // std::string::iterator start = rpn.input.begin();
    // // std::cout << std::string(input.begin(), input.end()) << std::endl;
    // std::cout << rpn.get_next_word(start) << std::endl;
    // std::cout << rpn.get_next_word(start) << std::endl;
    // std::cout << input << std::endl;
    // std::string::iterator begin = input.begin();
    // std::string::iterator end = input.begin();
    
    // std::string result = std::string(begin, end);
    // std::cout << atoi(result.c_str()) << std::endl;

    return 0;
}