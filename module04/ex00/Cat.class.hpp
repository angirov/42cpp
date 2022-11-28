#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <string>
# include <iostream>
# include "Animal.class.hpp"

class Cat : public Animal {
protected:
	std::string type;

public:
	Cat( void );
	Cat(Cat const &);
	~Cat( void );
	Cat & operator=(Cat const &);
	std::string getType() const;
	void makeSound() const;
};

#endif