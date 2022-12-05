#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP

# include "AForm.class.hpp"

class PresidentialPardonForm : public AForm {
private:
	const std::string target;
	bool execAction() const;

public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
};

#endif