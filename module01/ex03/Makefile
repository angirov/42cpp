NAME = unnecessary_violence

SRCS =	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

all: ${NAME}

${NAME}: $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

leaks:
	make re
	leaks --fullStacks --atExit -- ./${NAME}

valgrind:
	make re
	valgrind --leak-check=full ./${NAME} 

.PHONY: re clean fclean all leaks valgrind