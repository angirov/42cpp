#include "Intern.class.hpp"

Intern::Intern() {
	std::cout << ">>> Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &) {
	std::cout << ">>> Intern copy contructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << ">>> Intern destructor called" << std::endl;
}

Intern & Intern::operator=(Intern const &) {
	std::cout << ">>> Intern assignment operator is called" << std::endl;
	return *this;
}

AForm * Intern::makeForm(std::string formName, std::string target) const {
	std::string names[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	int idx;
	AForm * form = NULL;
	for(int i = 0; i < FORM_NUM; i++) {
		if (names[i] == formName)
			idx = i; 
	}
	switch (idx)
	{
	case 0:
		form = new RobotomyRequestForm(target);
		break;
	case 1:
		form = new PresidentialPardonForm(target);
		break;
	case 2:
		form = new ShrubberyCreationForm(target);
		break;
	default:
		throw InvalidFormException();
		std::cerr << "### Invalid form name. Intern failed to create a form." << std::endl;
		break;
	}
	if (form)
		std::cout << ">>> Intern created form " << formName << " for " << target << std::endl;
	return form;
}
