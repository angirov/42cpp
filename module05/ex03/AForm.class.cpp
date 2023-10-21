#include "AForm.class.hpp"

AForm::AForm(std::string inname, int ingradeSign, int ingradeExec) : 
	name(inname),
	gradeSign(isGrade(ingradeSign)),
	gradeExec(isGrade(ingradeExec)) {
	std::cout << ">>> Form constructor is called." << std::endl;
};

AForm::AForm(AForm const & other) : 
	name(other.name),
	gradeSign(other.gradeSign),
	gradeExec(other.gradeExec),
	issigned(other.issigned) {
	std::cout << ">>> Form copy constructor is called" << std::endl;
};

AForm::~AForm(void) {
	std::cout << ">>> Form destructor is called" << std::endl;
};

AForm & AForm::operator=(AForm const & other) {
	std::cout << ">>> Form copy operator is called (sign status is copied, name and grades stay the same)." << std::endl;
	issigned = other.issigned;
	return (*this);
};

std::string AForm::getName() const {
	return name;
}

bool AForm::getIssigned() const {
	return issigned;
}

int AForm::getGradeSign() const {
	return gradeSign;
}

int AForm::getGradeExec() const {
	return gradeExec;
}

int AForm::isGrade(int ingrade) const {
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

bool AForm::goodGrade(Bureaucrat const & b) const {
	if (b.getGrade() <= gradeSign)
		return true;
	else
	{
		throw AForm::GradeTooLowException();
		return false;
	}
}

bool AForm::goodSinged(AForm const &) const {
	if (issigned)
		return true;
	else
	{
		throw AForm::NotSignedException();
		return false;
	}
}

bool AForm::beSigned(Bureaucrat const & b) {
	if (goodGrade(b))
		return (issigned = true);
	else
		return false;
}

bool AForm::execute(Bureaucrat const & b) const {
	try {
		if (goodGrade(b) && goodSinged(*this))
			return execAction();

	} catch(GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	} catch(NotSignedException &e) {
		std::cout << e.what() << std::endl;
	}
	return false;
}

std::ostream & operator<<(std::ostream & o, AForm const & form)
{
	std::string ifsigned = (form.getIssigned() == true)? "signed" : "not signed";
	o << "Form " << form.getName() 
		<< " (" << ifsigned
		<< ", grade to sign: " << form.getGradeSign()
		<< ", to execute: " << form.getGradeExec() << ")";
	return o;
}
