#include "Harl.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 1)
    {
        std::cout << "Bad input format" << std::endl;
        return 1;
    }

    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
}