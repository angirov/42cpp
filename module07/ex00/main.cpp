#include <iostream>
#include "Templates.hpp"

int main() {
	int a = 1;
	int b = 2;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << ">>> swap is called" << std::endl;
	swap(a, b);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "min(a, b) = " << min(a,b) <<std::endl;
	std::cout << "max(a, b) = " << max(a,b) <<std::endl;
}