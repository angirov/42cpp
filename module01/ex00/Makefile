NAME = zombies

SRCS =	newZombie.cpp \
		randomChump.cpp \
		Zombie.cpp \
		main.cpp

OBJS =	${SRCS:.cpp=.o}

RM = rm -rf

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

all: ${NAME}

${NAME}:
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}