#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main()
{
	Bureaucrat * e = new Bureaucrat("Emmanuel", 150);

	Form * f = new Form("D4", 10, 20);
	std::cout << *f << " exits now!" << std::endl;
	e->signForm(*f);

	delete e;
	delete f;
	return 0;
}


// https://www.youtube.com/watch?v=0ojB8c0xUd8

// Basic rules and idioms for operator overloading
// https://stackoverflow.com/questions/4421706

// Open questions for both Bu and Fo
// << overloading
// copying of names
// 