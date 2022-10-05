NAME =	mapb

SRCS =	mapb.cpp \
		Contact.class.cpp \
		PhoneBook.class.cpp

CC =	c++
FLAGS =	-Wall -Werror -Wextra -std=c++98 -pedantic

all: ${NAME}

${NAME}:
	${CC} ${SRCS} ${FLAGS} -o ${NAME}

fclean:
	rm -f ${NAME}

re:	fclean all

.PHONY: re fclean all
