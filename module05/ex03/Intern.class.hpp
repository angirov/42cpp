#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# define FORM_NUM 3

# include <iostream>
# include <string>
# include "AForm.class.hpp"
# include "RobotomyRequestForm.class.hpp"
# include "PresidentialPardonForm.class.hpp"
# include "ShrubberyCreationForm.class.hpp"

class AForm;
class RobotomyRequestForm;
class PresidentialPardonForm;
class ShrubberyCreationForm;

class Intern {
public:
	Intern();
	Intern(Intern const &);
	~Intern();

	Intern & operator=(Intern const &);

	class InvalidFormException : std::exception {
	public:
		const char * what() const throw() {
			return "invalid form name input";
		}
	};
	AForm * makeForm(std::string formName, std::string target) const;
};

#endif