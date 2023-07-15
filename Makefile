CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = philo
SRCS = philo.c utils.c philo_utils.c init.c parse.c free_all.c death_checkers.c death_setters.c error.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

dre: fclean debug

.PHONY: all, clean, fclean, re, dre
