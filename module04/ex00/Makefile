NAME := tester

SRCS	:=	main.cpp \
			Animal.class.cpp \
			Cat.class.cpp \
			Dog.class.cpp \
			WrongAnimal.class.cpp \
			WrongCat.class.cpp
OBJS := ${SRCS:.cpp=.o}

CC 		:=	c++
FLAGS	:=	-Wall -Werror -Wextra -std=c++98
RM		:=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

${OBJS}: ${SRCS}
	${CC} ${FLAGS} -c ${SRCS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re