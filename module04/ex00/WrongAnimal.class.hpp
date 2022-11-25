#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

# include <string>
# include <iostream>

class WrongAnimal {
protected:
	std::string type;

public:
	WrongAnimal( void );
	WrongAnimal(WrongAnimal const &);
	virtual ~WrongAnimal( void );
	WrongAnimal & operator=(WrongAnimal const &);
	std::string getType() const;
	void makeSound() const; // the only diff: no virtual
};

#endif