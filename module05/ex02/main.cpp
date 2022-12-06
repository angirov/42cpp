#include "Bureaucrat.class.hpp"
#include "AForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"

#include <stdlib.h>

int main()
{
	Bureaucrat * e = new Bureaucrat("Emmanuel", 15);
	Bureaucrat * v = new Bureaucrat("Vladimir", 1);

	AForm * f = new PresidentialPardonForm("D4");
	std::cout << *f << " exits now!" << std::endl;
	e->signForm(*f);
	e->executeForm(*f);
	v->executeForm(*f);

	AForm * r =  new RobotomyRequestForm("R2");
	e->signForm(*r);
	for (int i = 0; i < 10; i++)
	{
		e->executeForm(*r);
	}

	AForm * s =  new ShrubberyCreationForm("S12");
	e->signForm(*s);
	e->executeForm(*s);

	delete e;
	delete f;
	delete r;
	delete s;
	return 0;
}

// int main()
// {
// 	for (int i=0; i < 10; i++)
// 	{
// 		std::cout << rand() % 2 << std::endl;
// 	}
// 	return 0;
// }


// https://www.youtube.com/watch?v=0ojB8c0xUd8

// Basic rules and idioms for operator overloading
// https://stackoverflow.com/questions/4421706

// Open questions for both Bu and Fo
// << overloading
// copying of names
// 