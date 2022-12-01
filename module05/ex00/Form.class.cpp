#include "Form.class.hpp"

// class Form {
// private:
// 	// A constant name.
// 	std::string const name;
// 	// A boolean indicating whether it is signed (at construction, it’s not).
// 	bool issigned;
// 	// A constant grade required to sign it.
// 	int const gradeSign;
// 	// And a constant grade required to execute i
// 	int const gradeExec;

Form::Form(std::string name, int gradeSign, int gradeExec) : issigned(false) {
	std::cout << "Form constructor is called" << std::endl;
}

Form::Form(Form const &) {
	
}

Form::~Form() {
	
}

std::ostream & Form::operator<<(std::ostream &) {
	
}

Form & Form::operator=(Form const &) {
	
}

std::string Form::getName() {
	
}

bool Form::getIssigned() {
	
}

int Form::getGradeSign() {
	
}

int Form::getGradeExec() {
	
}

bool Form::beSigned(Bureaucrat const &) {
	
}

