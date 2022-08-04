#include <iostream>
#include <string.h>

char *ft_strtoupper(std::string str)
{
	char *upper = new char[str.size() + 1];

	int i = 0;
	while (str[i])
	{
		upper[i] = toupper(str[i]);
		i++;
	}
	upper[i] = 0;
	return (upper);
}

int main(int argc, char **argv)
{
	char	buff[1000];

	for (int i = 1; argv[i]; i++)
	{
		char *upper  = ft_strtoupper(argv[i]);
		std::cout << upper;
		delete upper;
	}
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}