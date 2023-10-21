#include "Bureaucrat.class.hpp"
#include "AForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"

#include <stdlib.h>

int main()
{
	Bureaucrat e = Bureaucrat("Emmanuel", 140);
	Bureaucrat n = Bureaucrat("Nicolas", 70);
	Bureaucrat j = Bureaucrat("Jacque", 3);

	std::cout << "======== TESTING PresidentialPardonForm ========" << std::endl;
	AForm * f = new ShrubberyCreationForm("D4");
	std::cout << *f << " exists now!" << std::endl;
	e.signForm(*f);
	e.signForm(*f);
	e.executeForm(*f);
	n.executeForm(*f);
	delete f;

	std::cout << "======== TESTING RobotomyRequestForm ========" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		AForm * r =  new RobotomyRequestForm("R2");
		n.signForm(*r);
		j.executeForm(*r);
		delete r;
		std::cout << i << " ================" << std::endl;
	}

	std::cout << "======== TESTING PresidentialPardonForm ========" << std::endl;
	AForm * pr =  new PresidentialPardonForm("S12");
	e.signForm(*pr);
	j.signForm(*pr);
	j.executeForm(*pr);
	delete pr;

	std::cout << "======== FINISHED TESTING ========" << std::endl;

	return 0;
}

// https://www.youtube.com/watch?v=0ojB8c0xUd8

// Basic rules and idioms for operator overloading
// https://stackoverflow.com/questions/4421706

// Open questions for both Bu and Fo
// << overloading
// copying of names
// 