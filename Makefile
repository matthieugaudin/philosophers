NAME = philo
CC = cc -g
CCFLAGS = -Wall -Wextra -Werror

SRC =	src/main.c src/parse_data.c src/launch_philo.c src/init_data.c src/time.c \
		src/routine.c src/getters.c src/setters.c src/monitor.c src/check_meals.c \
		src/free_data.c

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