// https://man7.org/linux/man-pages/man3/strptime.3.html
// https://stackoverflow.com/questions/19482378/how-to-parse-and-validate-a-date-in-stdstring-in-c

#include "btc.class.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "ERROR: wrong number of arguments." << std::endl;
        exit(20);
    }
    char *input_path = argv[1];
    std::ifstream infile(input_path);
    if (!infile.is_open()) {
        std::cerr << "ERROR: file" << input_path << "could not be open. Check the name and permissions." << std::endl;
        exit(30);
    }
    Btc btc;
    btc.process_input(infile);
}
