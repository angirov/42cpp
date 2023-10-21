#include "Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(std::string inname, int ingrade) : name(inname){
	std::cout << ">>> Bureaucrat constructor is called" << std::endl;
	try {
		setGrade(ingrade);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
};

Bureaucrat::Bureaucrat(Bureaucrat const & other) : name(other.name), grade(other.grade) {
	std::cout << ">>> Bureaucrat copy constructor is called" << std::endl;
};

Bureaucrat::~Bureaucrat(void) {
	std::cout << ">>> Bureaucrat destructor is called" << std::endl;
};

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other) {
	std::cout << ">>> Bureaucrat copy operator is called (grade is copied, name stays the same)." << std::endl;
	grade = other.grade;
	return (*this);
};

std::string Bureaucrat::getName() const {
	return (name);
};

int Bureaucrat::getGrade() const {
	return (grade);
};

void Bureaucrat::setGrade(int ingrade){
		if (ingrade < 1)
			throw GradeTooHighException();
		else if (ingrade > 150)
			throw GradeTooLowException();
		else
		{
			grade = ingrade;
			std::cout << ">>> Grade changed to " << grade << std::endl;
		}
};

void Bureaucrat::incrementGrade() {
	std::cout << ">>> Grade incrementation for " << *this << std::endl;
	try { 
		setGrade(grade - 1); 
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
};

void Bureaucrat::decrementGrade() {
	std::cout << ">>> Grade decrementation for " << *this << std::endl;
	try { 
		setGrade(grade + 1); 
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
};

void Bureaucrat::signForm(AForm & f) {
	try {
		if (f.beSigned(*this))
			std::cout << *this << " signed " << f << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << *this << " couldn’t sign " << f 
		<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm & f) {
	try {
		if (f.execute(*this))
			std::cout << *this << " executed " << f << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << *this << " couldn’t sign " << f 
		<< " because " << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, Bureaucrat & b) {
	os << b.getName() << ", grade " << b.getGrade();
	return os;
};
