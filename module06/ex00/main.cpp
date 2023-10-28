#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include "ScalarConverter.class.hpp"

int main(int argc, char ** argv) {
	if (argc != 2)
	{
		std::cerr << "### Wrong number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}


// https://www.learncpp.com/cpp-tutorial/literals/
// https://cplusplus.com/doc/oldtutorial/typecasting/

// ChatGPT:
// The phrase "most common form" in the context of a string representation of a C++ literal acknowledges that there can be variations or alternative ways to represent the same literal value in the C++ programming language. While there are standard or typical ways to express literals, there might be different formats, representations, or encoding schemes that could also be valid.

// For instance, consider:

// Integer Literals:

// Decimal: 42
// Hexadecimal: 0x2A
// Binary: 0b101010
// Floating-Point Literals:

// Standard notation: 3.14
// Scientific notation: 3.14e0
// Character and String Literals:

// Single character: 'A'
// Escape sequences in strings: "Hello\nWorld"
// The "most common form" often refers to the typical, straightforward representation that programmers use and understand easily. However, in some cases, special notations, alternative bases (like hexadecimal or binary for integers), or escape sequences in strings might be considered variations of these common forms.

// So, emphasizing the "most common form" highlights the prevalent or widely accepted way of representing a literal in C++, while acknowledging that there might be other valid representations.
