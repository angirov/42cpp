NAME = sed

SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -std=c++98

all:
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re