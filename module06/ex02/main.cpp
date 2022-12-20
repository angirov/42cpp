#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <unistd.h>

class Base {
public:
	virtual void doNothing() {};
	};

class A : public Base {};
class B : public Base {};
class C : public Base {};

void printByte(void * ptr)
{
	char *c = (char *)ptr;

	for (int i=0; i < 8; i++)
	{
		if (*c & ((1 << 7) >> i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, " ", 1);
}

void printMem(void * ptr, int size)
{
	char *c = (char *)ptr;

	for (int i=0; i < size; i++)
	{
		printByte(c + i);
	}
	write(1, "\n", 1);
}

Base * generate(void)
{
	srand((unsigned int)time(NULL));
	int r = rand()%3;
	Base * p;
	switch (r)
	{
	case 0:
		p = new A();
		break;
	case 1:
		p = new B();
		break;
	case 2:
		p = new C();
		break;
	}
	return p;
}

void identify(Base* p)
{
	std::string message = ">>> Actual type pointed to:  ";
	if (dynamic_cast<A *>(p))
		message += "A";
	else if (dynamic_cast<B *>(p))
		message += "B";
	else if (dynamic_cast<C *>(p))
		message += "C";
	else
		message += "UNKNOWN";
	std::cout << message << std::endl;
}

void identify(Base& p)
{
	enum types {t_A, t_B, t_C};
	std::string names[] = {"A", "B", "C"};
	int flags = 0;
	std::string message = ">>> Actual type reffered to: ";

	try {dynamic_cast<A &>(p);}
	catch(std::bad_cast& bc) {
		flags |= 1 << t_A;
	}
	// printMem(&flags, sizeof(int));
	try {dynamic_cast<B &>(p);}
	catch(std::bad_cast& bc) {
		flags |= 1 << t_B;
	}
	// printMem(&flags, sizeof(int));
	try {dynamic_cast<C &>(p);}
	catch(std::bad_cast& bc) {
		flags |= 1 << t_C;
	}
	// printMem(&flags, sizeof(int));
	
	for (int i = 0; i < 3; i++) {
		if (!(flags & 1 << i))
			message += names[i];
	}
	std::cout << message << std::endl;
	return;
}

int main()
{
	Base *base;
	for (int i = 0; i < 10; i++)
	{
		std::cout << " =========== [ " << i << " ] ==========" << std::endl;
		base = generate();
		identify(base);
		identify(*base);
		delete base;
		sleep(1);
	}
	return 0;
}