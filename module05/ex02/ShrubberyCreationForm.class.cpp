#include "ShrubberyCreationForm.class.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << ">>> ShrubberyCreationForm constructor is called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << ">>> ShrubberyCreationForm destructor is called." << std::endl;
}

std::ofstream & ShrubberyCreationForm::tree(std::ofstream & f) const {
	f << "       ###" << std::endl;
	f << "      #o###" << std::endl;
	f << "    #####o###" << std::endl;
	f << "   #o#=#|#=###" << std::endl;
	f << "    ###=|=#o#" << std::endl;
	f << "     # }|{  #" << std::endl;
	f << "       }|{" << std::endl;
	f << std::endl;
	return f;
}

bool ShrubberyCreationForm::execAction() const {
	std::string filename = target + "_shrubbery";
	std::ofstream myfile;
	myfile.open(filename.c_str());
	if (myfile.is_open())
	{
		for (int i = 0; i < 3; i++)
			this->tree(myfile);
		myfile.close();
		return true;
	}
	else
	{
		std::cerr << "### File could not be open" << std::endl;
	return false;
	}
}
