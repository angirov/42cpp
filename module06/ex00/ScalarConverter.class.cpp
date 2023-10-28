#include "ScalarConverter.class.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << ">>> ScalarConverter constructor is called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << ">>> ScalarConverter destructor is called" << std::endl;
}

bool ScalarConverter::isNumeric(std::string str) {
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

bool ScalarConverter::isPseudo(std::string s) {
	if (s == "-inff" || s == "+inff" || s == "nanf"
		|| s == "nan" || s == "-inf" || s == "+inf"
		|| s == "inf" || s == "inff")
		return (true);
	return (false);
}

void ScalarConverter::convert(std::string input)
{
	const char * cstr = input.c_str();
	if (input.length() == 1 && !isNumeric(input)){
		char c = static_cast<char>(input[0]);
		displayChar(c);
	}
	else if (isPseudo(input) || (isNumeric(input) && input.find('.') != std::string::npos)) {
		if (input.find('f') == std::string::npos) {
			double num = static_cast<double>(strtod(cstr, NULL));
			displayDouble(num);
		}
		else {
			float num = static_cast<float>(strtod(cstr, NULL));
			displayFloat(num);
		}
	}
	else if (isNumeric(input) && input.find('f') == std::string::npos && input.find('.') == std::string::npos) {
		int num = static_cast<int>(strtod(cstr, NULL));
		displayInt(num);
	}	else {
		std::cerr << "### Invalid input string" << std::endl;
	}
}

void ScalarConverter::displayChar(char input)
{
	// std::cout << ">>> Type: Char" << std::endl;
	if (input < 32 || input >= 127 )
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << input << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(input) << std::endl;

	std::cout << "float: " << static_cast<float>(input) << (static_cast<bool>(std::fmod(input, 1)) ? "f" : ".0f") << std::endl;

	std::cout << "double: " << static_cast<double>(input) << (static_cast<bool>(std::fmod(input, 1)) ? "" : ".0") << std::endl;
}

void ScalarConverter::displayInt(int input)
{
	// std::cout << ">>> Type: Int" << std::endl;
	if (input > std::numeric_limits<char>::max() || input < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (input < 32 || input >= 127 )
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;

	std::cout << "int: " << input << std::endl;

	std::cout << "float: " << static_cast<float>(input) << (static_cast<bool>(std::fmod(input, 1)) ? "f" : ".0f") << std::endl;

	std::cout << "double: " << static_cast<double>(input) << (static_cast<bool>(std::fmod(input, 1)) ? "" : ".0") << std::endl;
}

void ScalarConverter::displayFloat(float input)
{
	// std::cout << ">>> Type: Float" << std::endl;
	if (input > std::numeric_limits<char>::max() || input < std::numeric_limits<char>::min() || input != input)
		std::cout << "char: impossible" << std::endl;
	else if (input < 32 || input >= 127 )
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;

	if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min() || input != input)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(input) << std::endl;

	std::cout << "float: " << input << (static_cast<bool>(std::fmod(input, 1)) ? "f" : ".0f") << std::endl;

	std::cout << "double: " << static_cast<double>(input) << (static_cast<bool>(std::fmod(input, 1)) ? "" : ".0") << std::endl;
}

void ScalarConverter::displayDouble(double input)
{
	// std::cout << ">>> Type: Double" << std::endl;
	if (input > std::numeric_limits<char>::max() || input < std::numeric_limits<char>::min() || input != input)
		std::cout << "char: impossible" << std::endl;
	else if (input < 32 || input >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;

	if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min() || input != input)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(input) << std::endl;

	std::cout << "float: " << static_cast<float>(input) << (static_cast<bool>(std::fmod(input, 1)) ? "f" : ".0f") << std::endl;

	std::cout << "double: " << input << (static_cast<bool>(std::fmod(input, 1)) ? "" : ".0") << std::endl;
}
