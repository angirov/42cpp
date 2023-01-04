NAME = sed

FILENAME = test.file
DUMMYTEXT = "Some dummy text to replace"
SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -std=c++98

all: ${NAME}
	echo ${DUMMYTEXT} > ${FILENAME}

${NAME}: ${SRCS}
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

clean:
	${RM} ${OBJS} ${FILENAME} ${FILENAME}.replace

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re