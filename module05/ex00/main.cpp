#include "Bureaucrat.class.hpp"

int main()
{
	Bureaucrat e = Bureaucrat("Emmanuel", 150);
	Bureaucrat j = Bureaucrat("Jacque", 1);
	Bureaucrat n = Bureaucrat("Nicolas", 200);

	std::cout << "$$$ Print out: ";
	std::cout << e <<  std::endl;

	e.decrementGrade();
	e.incrementGrade();

	j.incrementGrade();
	j.decrementGrade();

	return 0;
}


// https://www.youtube.com/watch?v=0ojB8c0xUd8

// Basic rules and idioms for operator overloading
// https://stackoverflow.com/questions/4421706

// Open questions for both Bu and Fo
// << overloading
// copying of names
// check input initializing const variables of a class
