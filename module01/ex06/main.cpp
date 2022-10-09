#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Bad input format" << std::endl;
        return 1;
    }

    Harl harl;
    std::string inlevel(argv[1]);

    harl.set_level(inlevel);
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
}