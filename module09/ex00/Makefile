NAME := btc

SRCS	:=	main.cpp
HDRS	:=	btc.class.hpp
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

.PHONY: all clean fclean re