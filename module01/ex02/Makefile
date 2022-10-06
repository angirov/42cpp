NAME = brains

SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

all:
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re