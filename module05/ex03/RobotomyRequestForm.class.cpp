#include "RobotomyRequestForm.class.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("RobotomyRequestForm", 25, 5), target(target) {
	std::cout << ">>> RobotomyRequestForm constructor is called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << ">>> RobotomyRequestForm destructor is called." << std::endl;
}

bool RobotomyRequestForm::execAction() const {
	if (rand() % 2)
		std::cout << "$$$ " << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "$$$ " << "Robotomy failed for " << target << std::endl;
	return true;
}
