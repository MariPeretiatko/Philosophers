NAME = philo

SRC = src/error.c\
	src/init.c\
	src/utils.c\
	src/utils_usleep.c\
	src/free.c\
	src/philosopher_actions.c\
	src/philosopher_state.c\
	main.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus