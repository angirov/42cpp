NAME = megaphone
SRCS = megaphone.cpp

CC = c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic

all:		${NAME}

${NAME}:
			${CC} ${SRCS} ${FLAGS} -o ${NAME} 

leaks:
	make re
	leaks --fullStacks --atExit -- ./${NAME}

fclean:	
			rm -f ${NAME}

re:			fclean all

.PHONY:		re fclean all