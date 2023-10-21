#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main()
{
	Bureaucrat e = Bureaucrat("Emmanuel", 150);
	Bureaucrat j = Bureaucrat("Jacque", 1);

	Form f = Form("D4", 10, 20);
	std::cout << f << " exists now!" << std::endl;
	e.signForm(f);
	j.signForm(f);

	return 0;
}


// https://www.youtube.com/watch?v=0ojB8c0xUd8

// Basic rules and idioms for operator overloading
// https://stackoverflow.com/questions/4421706

// Open questions for both Bu and Fo
// << overloading
// copying of names
// 