#include "Brain.class.hpp"

Brain::Brain( void ) {
	std::cout << "Brain default constructor is called." << std::endl;
};

Brain::Brain(Brain const & orig) {
	for (int i = 0; i < NUM_IDEAS; i++)
	{
		ideas[i] = orig.getIdea(i);
	}
	ideaCounter = orig.getIdeaCounter();
};

Brain::~Brain() {
	std::cout << "Brain destructor is called." << std::endl;
};

Brain & Brain::operator=(Brain const & orig) {
	std::cout << ">>> Brain copy operator is called" << std::endl;
	for (int i = 0; i < NUM_IDEAS; i++)
	{
		ideas[i] = orig.getIdea(i);
	}
	ideaCounter = orig.getIdeaCounter();
	return (*this);
};

void Brain::newIdea(std::string idea) {
	int i = ideaCounter % NUM_IDEAS;

	ideas[i] = idea;
	ideaCounter++;
};

std::string Brain::getIdea(int index) const {
	return (ideas[index]);
};

int Brain::getIdeaCounter() const {
	return (ideaCounter);
};

void Brain::printIdeas() const {
	std::cout << "Ideas counter: " << ideaCounter << std::endl;
	for (int i = 0; i < NUM_IDEAS; i++)
	{
		if (ideas[i].length())
			std::cout << "[" << i << "]: " << ideas[i] << std::endl;
	}
};