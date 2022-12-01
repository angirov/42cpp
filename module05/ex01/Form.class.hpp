#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <string>
# include <iostream>
# include <sstream>
# include "Bureaucrat.class.hpp"

class Form {
private:
	// A constant name.
	std::string const name;
	// A boolean indicating whether it is signed (at construction, it’s not).
	bool issigned;
	// A constant grade required to sign it.
	int const gradeSign;
	// And a constant grade required to execute i
	int const gradeExec;

public:
	Form(std::string name, int gradeSign, int gradeExec);
	Form(Form const &);
	~Form();
	Form & operator=(Form const &);

	std::string getName();
	bool getIssigned();
	int getGradeSign();
	int getGradeExec();

	bool beSigned(Bureaucrat const &);
};

#endif