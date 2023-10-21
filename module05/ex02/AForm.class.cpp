#include "AForm.class.hpp"

AForm::AForm(std::string inname, int ingradeSign, int ingradeExec) : 
	name(inname),
	gradeSign(isGrade(ingradeSign)),
	gradeExec(isGrade(ingradeExec)),
	issigned(false),
	isexecuted(false) {
	std::cout << "Form constructor is called." << std::endl;
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

bool AForm::goodGradeSign(Bureaucrat const & b) const {
	if (b.getGrade() <= gradeSign)
		return true;
	else
	{
		throw AForm::GradeTooLowException();
		return false;
	}
}

bool AForm::goodGradeExec(Bureaucrat const & b) const {
	if (b.getGrade() <= gradeExec)
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
	if (issigned) {
		std::cerr << "### Form is already signed!" << std::endl;
		return false;
	}
	else if (goodGradeSign(b))
		return (issigned = true);
	else
		return false;
}

bool AForm::execute(Bureaucrat const & b) {
	if (isexecuted) {
		std::cerr << "### Form is already executed!" << std::endl;
		return false;
	}
	try {
		if (goodGradeExec(b) && goodSinged(*this))
			if (execAction()) {
				return (isexecuted = true);
			}
	} catch(GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	} catch(NotSignedException &e) {
		std::cerr << e.what() << std::endl;
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
