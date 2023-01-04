#include "Harl.hpp"

Harl::Harl() {
    this->levels[0] = "DEBUG";
    this->levels[1] = "INFO";
    this->levels[2] = "WARNING";
    this->levels[3] = "ERROR";

    this->funcs[0] = &Harl::debug;
    this->funcs[1] = &Harl::info;
    this->funcs[2] = &Harl::warning;
    this->funcs[3] = &Harl::error;

    std::cout << ">>> Harl object constructed" << std::endl;
}

Harl::~Harl() {
    std::cout << ">>> Harl object destructed" << std::endl;
}

void Harl::complain( std::string level ) {
    for (int i=0; i < 4; ++i)
        if (level == levels[i])
        {
            std::cout << "[ " << level << " ]" << std::endl;
            (this->*funcs[i])();
            std::cout << std::endl;
        }
}

void Harl::debug( void ) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! else If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
