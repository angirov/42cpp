#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <string>
# include <iostream>

class Animal {
protected:
	std::string type;

public:
	Animal( void );
	Animal(Animal const &);
	virtual ~Animal( void );
	Animal & operator=(Animal const &);
	virtual std::string getType() const;
	virtual void makeSound() const;
};

#endif