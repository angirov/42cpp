#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <string>
# include <iostream>
# include <sstream>
# include "Bureaucrat.class.hpp"

class Bureaucrat;

class Form {
private:
	// A constant name.
	std::string const name;
	// A constant grade required to sign it.
	int const gradeSign;
	// And a constant grade required to execute i
	int const gradeExec;
	// A boolean indicating whether it is signed (at construction, it’s not).
	bool issigned;

public:
	Form(std::string name, int gradeSign, int gradeExec);
	Form(Form const &);
	~Form();
	Form & operator=(Form const &);

	std::string getName() const;
	bool getIssigned() const;
	int getGradeSign() const;
	int getGradeExec() const;
	int isGrade(int ingrade) const;

	bool beSigned(Bureaucrat const & b);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Grade is too high.");
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Grade is too low.");
		}
	};
};

std::ostream & operator<<(std::ostream & o, Form const & form);

#endif