NAME = zombies

SRCS =	Zombie.cpp \
		main.cpp \
		zombieHorde.cpp

OBJS =	${SRCS:.cpp=.o}

RM = rm -rf

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

all: ${SRCS}
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}