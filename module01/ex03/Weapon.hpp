#include <string>

class Weapon {
private:
	std::string	type;
public:
	std::string getType();
	void		setType(std::string type);
};