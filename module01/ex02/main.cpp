#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *sp = &str;
	std::string &sr = str; // just another "name" for str

	std::cout << "The memory address of the string variable:" << "\t" << &str << std::endl;
	std::cout << "The memory address held by stringPTR:" << "\t\t" << &sp << std::endl;
	std::cout << "The memory address held by stringREF:" << "\t\t" << &sr << std::endl << "\n";

	std::cout << "The value of the string variable:" << "\t\t" << str << std::endl;
	std::cout << "The value pointed to by stringPTR:" << "\t\t" << sp << std::endl;
	std::cout << "The value pointed to by stringREF:" << "\t\t" << sr << std::endl;

	return 0;
}