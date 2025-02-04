NAME = philo
CC = cc
CCFLAGS = -Wall -Wexta

SRC = philo/src/main.c

OBJ = $(SRC:.c=.o)

%.o: %.c
		$(CC) $(CCFLAGS) -o $@ -c $^

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re