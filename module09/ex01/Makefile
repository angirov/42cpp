NAME := rpn

SRCS	:=	main.cpp
HDRS	:=	rpn.hpp

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

test:
	./${NAME} "5 7 +"
	./${NAME} "5 7 -"
	./${NAME} "5 7 *"
	./${NAME} "55 5 /"
	./${NAME} "5"
	./${NAME} "5 5 5 + +"
	./${NAME} "5 5 + 5 +"

	-./${NAME} "5 5 5 + + +"
	-./${NAME} "5 7"
	-./${NAME} ""
	-./${NAME} "4 5 foo bar"
	-./${NAME}
	-./${NAME} "+ 55 77"
	-./${NAME} "55 + 77"
	-./${NAME} "9 9 9 9 /"
	-./${NAME} "-77 -7 / +"
	-./${NAME} "-13 0 /"
	-./${NAME} "-13 999999999999 /"

.PHONY: all clean fclean re