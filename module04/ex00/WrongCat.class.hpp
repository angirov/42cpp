#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

# include <string>
# include <iostream>
# include "WrongAnimal.class.hpp"

class WrongCat : public WrongAnimal {
protected:
	std::string type;

public:
	WrongCat( void );
	WrongCat(WrongCat const &);
	~WrongCat( void );
	WrongCat & operator=(WrongCat const &);
	void makeSound() const;
};

#endif