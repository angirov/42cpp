#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <string>
# include <iostream>
# include "Brain.class.hpp"

class Animal {
private:
	Brain* brain;

protected:
	std::string type;

public:
	Animal( void );
	Animal(Animal const &);
	virtual ~Animal( void );
	Animal & operator=(Animal const & rhs);
	virtual std::string getType() const;
	virtual void makeSound() const;

	void newIdea(std::string idea) const;
	std::string getIdea(int index) const;
	void printIdeas(void) const;
};

#endif