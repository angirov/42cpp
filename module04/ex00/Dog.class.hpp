#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <string>
# include <iostream>
# include "Animal.class.hpp"

class Dog : public Animal {
protected:
	std::string type;

public:
	Dog( void );
	Dog(Dog const &);
	~Dog( void );
	Dog & operator=(Dog const &);
	void makeSound() const;
};

#endif