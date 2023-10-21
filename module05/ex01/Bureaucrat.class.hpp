#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <string>
# include <iostream>
# include "Form.class.hpp"

class Form;

class Bureaucrat {
private:
	std::string const name;
	int grade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & other);
	~Bureaucrat(void);

	Bureaucrat & operator=(Bureaucrat const & other);

	std::string getName() const;
	int getGrade() const;
	void setGrade(int grade);
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Exception: Grade too high. Must be between 1 and 150");
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Exception: Grade too low. Must be between 1 and 150");
		}
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat & b);

#endif