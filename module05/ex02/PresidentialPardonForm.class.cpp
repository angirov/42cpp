#include "PresidentialPardonForm.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << ">>> PresidentialPardonForm constructor is called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << ">>> PresidentialPardonForm destructor is called." << std::endl;
}

bool PresidentialPardonForm::execAction() const {
	std::cout << "$$$ " << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return true;
}
