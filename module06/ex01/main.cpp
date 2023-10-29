#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include "Serializer.class.hpp"

struct Data {
	int x;
	int y;
	Data() : x(0), y(0) {};
	void print() { 
		std::cout << "Printing Data struct:\n" <<
		"x: " << x << std::endl <<
		"y: " << y << std::endl;
	}
};

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

int main()
{
	uintptr_t i;

	std::cout << "Sizeof( Data ): " << sizeof(Data) << std::endl;
	Data *p= new Data();
	std::cout << "Address kept in p: " << p << std::endl;
	printMem(p, sizeof(Data));
	p->x = 42;
	p->y = 42;
	printMem(p, sizeof(Data));
	p->print();

	std::cout << ">>>>> Serializer  is  called: i <- p" << std::endl;
	i = Serializer::serialize(p);
	std::cout << "Value of i in hex:   " << std::hex << i  << std::endl;

	std::cout << ">>>>> Deserializer is called: q <- i" << std::endl;
	Data *q = Serializer::deserialize(i);
	std::cout << std::dec << "Address kept in q: " << q  << std::endl;
	printMem(q, sizeof(Data));
	q->print();

	delete q;
}

// intptr_t, uintptr_t - integer types wide enough to hold pointers