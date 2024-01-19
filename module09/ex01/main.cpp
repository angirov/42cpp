#include <iostream>
#include <string>
#include <stdlib.h>
#include "rpn.hpp"

void exit_msg(std::string msg, int n) {
    std::cerr << "rpn: " << msg << std::endl;
    exit(n);
}

int main(int argc, char** argv) {

    if (argc > 2 || argc <= 1)
        exit_msg("Bad input: Wrong number of arguments! Need only one string.", 2); 
    std::string input = argv[1];

    Rpn rpn = Rpn(input);
    try {
        rpn.run();
    } catch(const char *e_msg) {
        std::cout << e_msg << std::endl;
        exit(4);
    }
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