#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# define NUM_IDEAS 100

# include <string>
# include <iostream>

class Brain {
private:
	std::string ideas[NUM_IDEAS];
	int	ideaCounter;

public:
	Brain( void );
	Brain(Brain const &);
	~Brain();
	Brain & operator=(Brain const &);

	void newIdea(std::string idea);
	int getIdeaCounter(void) const;
	std::string getIdea(int index) const;
	void printIdeas(void) const;
};

#endif