#include <iostream>
#include <string>
#include <cmath>
#include <limits>

class ScalarConverter {
public:
    ~ScalarConverter();
    static void convert(std::string input);

private:
    ScalarConverter();
    static bool isNumeric(std::string input);
    static bool isPseudo(std::string input);
    static void displayChar(char input);
    static void displayInt(int input);
    static void displayFloat(float input);
    static void displayDouble(double input);
};
