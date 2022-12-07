#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP

# include <fstream>
# include "AForm.class.hpp"

class ShrubberyCreationForm : public AForm {
private:
	const std::string target;
	bool execAction() const;
	std::ofstream & tree(std::ofstream & f) const;

public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
};

#endif