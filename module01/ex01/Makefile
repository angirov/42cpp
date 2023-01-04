NAME = zombies

SRCS =	Zombie.cpp \
		main.cpp \
		zombieHorde.cpp

OBJS =	${SRCS:.cpp=.o}

RM = rm -rf

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

all: ${NAME}

${NAME}: ${SRCS}
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}


re: fclean all

leaks:
	make re
	leaks --fullStacks --atExit -- ./${NAME}

valgrind:
	make re
	valgrind --leak-check=full ./${NAME} 

.PHONY: re clean fclean all leaks valgrind