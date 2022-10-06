NAME = unnecessary_violence

SRCS =	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

CC = g++

FLAGS = -Wall -Werror -Wextra -std=c++98

all:
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: all clean fclean all