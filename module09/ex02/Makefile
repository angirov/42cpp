NAME := PmergeMe

SRCS	:=	main.cpp PmergeMe.cpp
HDRS	:=	PmergeMe.hpp

OBJS	:= ${SRCS:.cpp=.o}

CC 		:=	c++
FLAGS	:=	-Wall -Werror -Wextra -std=c++98
RM		:=	rm -rf

all: ${NAME}

${NAME}: ${OBJS} 
	${CC} ${OBJS} -o ${NAME}

${OBJS}: ${SRCS} ${HDRS}
	${CC} ${FLAGS} -c ${SRCS}

clean:
	${RM} ${OBJS} *.gch

fclean: clean
	${RM} ${NAME}

re: fclean all

# jot [reps [begin [end [sep]]]]
mac-test:
	./${NAME} `jot -r 3000 1 3000 ' '`
linux-test:
	./${NAME} `shuf -i 1-1000 -n 1000 | tr "\n" " "`
.PHONY: all clean fclean re