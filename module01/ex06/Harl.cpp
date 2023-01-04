#include "Harl.hpp"

Harl::Harl() : level(-1) {

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

void Harl::set_level( std::string inlevel ) {
    for (int i=0; i < 4; ++i)
        if (inlevel == levels[i])
        {
            this->level = i;
        }
    if (this->level < 0)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain( std::string level ) {
    if (this->level < 0)
        return;
    for (int i=0; i < 4; ++i)
        if (level == levels[i] && this->level <= i)
        {
            std::cout << "[ " << level << " ]" << std::endl;
            (this->*funcs[i])();
        }
}

void Harl::debug( void ) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! else If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}
