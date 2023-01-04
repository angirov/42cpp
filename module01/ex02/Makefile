NAME = brains

SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

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

.PHONY: all clean fclean re leaks valgrind