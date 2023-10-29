NAME := tester

SRCS	:=	main.cpp \
			Serializer.class.cpp

HDRS	:=	Serializer.class.hpp

OBJS	:= ${SRCS:.cpp=.o}

CC 		:=	c++
FLAGS	:=	-Wall -Werror -Wextra -std=c++98
RM		:=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

${OBJS}: ${SRCS}
	${CC} ${FLAGS} -c ${SRCS} $(HDRS)

clean:
	${RM} ${OBJS} *.gch

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re