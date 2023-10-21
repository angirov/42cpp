#include "RobotomyRequestForm.class.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << ">>> RobotomyRequestForm constructor is called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << ">>> RobotomyRequestForm destructor is called." << std::endl;
}

bool RobotomyRequestForm::execAction() const {
	std::cout << "    --------------------------------------------------------------" << std::endl;
	if (rand() % 2)
		std::cout << "$$$ " << target << " HAS BEEN ROBOTOMIZED ___SUCCESSFULLY___." << std::endl;
	else
		std::cout << "### " << "ROBOTOMY ___FAILED___ FOR " << target << std::endl;
	std::cout << "    --------------------------------------------------------------" << std::endl;
	return true;
}
