#include "Form.class.hpp"

Form::Form(std::string inname, int ingradeSign, int ingradeExec) : 
	name(inname),
	gradeSign(isGrade(ingradeSign)),
	gradeExec(isGrade(ingradeExec)) {
	std::cout << "Form constructor is called." << std::endl;
};

Form::Form(Form const & other) : 
	name(other.name),
	gradeSign(other.gradeSign),
	gradeExec(other.gradeExec),
	issigned(other.issigned) {
	std::cout << ">>> Form copy constructor is called" << std::endl;
};

Form::~Form(void) {
	std::cout << ">>> Form destructor is called" << std::endl;
};

Form & Form::operator=(Form const & other) {
	std::cout << ">>> Form copy operator is called (sign status is copied, name and grades stay the same)." << std::endl;
	issigned = other.issigned;
	return (*this);
};

std::string Form::getName() const {
	return name;
}

bool Form::getIssigned() const {
	return issigned;
}

int Form::getGradeSign() const {
	return gradeSign;
}

int Form::getGradeExec() const {
	return gradeExec;
}

int Form::isGrade(int ingrade) const {
	if (ingrade < 1)
	{
		std::cerr << "### Greade " << ingrade << " is too high. Set to maximum (1)" << std::endl;
		return 1;
	}
	if (ingrade > 150)
	{
		std::cerr << "### Greade " << ingrade << " is too low. Set to minimum (150)" << std::endl;
		return 150;
	}
	return ingrade;
}

bool Form::beSigned(Bureaucrat const & b) {
	if (b.getGrade() <= gradeSign)
		return (issigned = true);
	else
		throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form const & form)
{
	std::string ifsigned = (form.getIssigned() == true)? "signed" : "not signed";
	o << "Form " << form.getName() 
		<< " (" << ifsigned
		<< ", grade to sign: " << form.getGradeSign()
		<< ", to execute: " << form.getGradeExec() << ")";
	return o;
}
