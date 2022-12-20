#include <stdint.h>
#include <iostream>
#include <unistd.h>

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

class Data {
public:
	int i = 0;
};

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	uintptr_t i;

	std::cout << "Sizeof( Data ): " << sizeof(Data) << std::endl;
	Data *p = new Data();
	std::cout << "Address kept in p: " << p  << std::endl;
	printMem(p, sizeof(Data));
	p->i = 42;
	printMem(p, sizeof(Data));

	i = serialize(p);
	std::cout << "Value of i in hex:   " << std::hex << i  << std::endl;

	Data *q = deserialize(i);
	std::cout << "Address kept in q: " << q  << std::endl;
	printMem(q, sizeof(Data));
	delete q;
}