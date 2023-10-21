#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP

# include <string>
# include <iostream>
# include <sstream>
# include "Bureaucrat.class.hpp"

class Bureaucrat;

class AForm {
private:
	// A constant name.
	std::string const name;
	// A constant grade required to sign it.
	int const gradeSign;
	// And a constant grade required to execute i
	int const gradeExec;
	// A boolean indicating whether it is signed (at construction, it’s not).
	bool issigned;
	bool isexecuted;

public:
	AForm(std::string name, int gradeSign, int gradeExec);
	AForm(AForm const &);
	virtual ~AForm();
	AForm & operator=(AForm const &);

	std::string getName() const;
	bool getIssigned() const;
	int getGradeSign() const;
	int getGradeExec() const;
	int isGrade(int ingrade) const;

	bool goodGradeSign(Bureaucrat const &) const;
	bool goodGradeExec(Bureaucrat const &) const;
	bool goodSinged(AForm const &) const;
	bool beSigned(Bureaucrat const & b);
	bool execute(Bureaucrat const & b);
	virtual bool execAction() const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Exception: Grade is too high.");
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Exception: Grade is too low.");
		}
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Exception: Form is not yet signed.");
		}
	};
};

std::ostream & operator<<(std::ostream & o, AForm const & form);

#endif