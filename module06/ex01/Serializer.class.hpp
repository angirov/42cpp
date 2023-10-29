#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

# include <stdint.h>
# include <unistd.h>
#include <iostream>

struct Data;

class Serializer {
private:
	Serializer();
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif