#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP

# include <stdlib.h>
# include "AForm.class.hpp"

class RobotomyRequestForm : public AForm {
private:
	const std::string target;
	bool execAction() const;

public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
};

#endif