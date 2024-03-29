#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl {
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    std::string levels[4];
    void (Harl::* funcs[4])();
public:
    Harl();
    ~Harl();
    void complain( std::string level );
};

#endif