#include <iostream>
#include <string>
#include <cmath>
#include <limits>

bool isNumeric(std::string str) {
	int len = str.length();
	char c;

	for (int i = 0; i < len; i++) {
		c = str[i];
		if (i == 0 && (c == '-' || c == '+'))
			continue ;
		else if (i == len-1 && c == 'f')
			continue ;
		else if (isdigit(c) || c == '.')
			continue ;
		else
			return (false);
	}
	return (true);
}

bool isPseudo(std::string s) {
	if (s == "-inff" || s == "+inff" || s == "nanf"
		|| s == "nan" || s == "-inf" || s == "+inf"
		|| s == "inf" || s == "inff")
		return (true);
	return (false);
}

bool isValidInput(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "### Wrong number of arguments" << std::endl;
		return false;
	}
	std::string str = argv[1];
	if (isNumeric(str) || isPseudo(str) || str.length() == 1)
		return true;
	else
	{
		std::cerr << "### Invalid input string" << std::endl;
		return false;
	}
}

double convert(char *cstr)
{
	if (isPseudo(cstr) || isNumeric(cstr))
		return strtod(cstr, NULL);
	else
		return static_cast<double>(cstr[0]);
}

void displayLiteral(char* str)
{
	double num = convert(str);
	if (isPseudo(str) || num > std::numeric_limits<char>::max() || num < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (num < 32 || num >= 127 )
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;

	if (isPseudo(str) || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	std::cout << "float: " << static_cast<float>(num) << (static_cast<bool>(std::fmod(num, 1)) ? "f" : ".0f") << std::endl;

	std::cout << "double: " << static_cast<double>(num) << (static_cast<bool>(std::fmod(num, 1)) ? "" : ".0") << std::endl;
}


int main(int argc, char** argv)
{
	if (isValidInput(argc, argv))
	{
		
		displayLiteral(argv[1]);
	}
	else
		return 1;
	return 0;
}


// https://www.learncpp.com/cpp-tutorial/literals/