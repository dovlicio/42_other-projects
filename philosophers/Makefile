NAME = philo
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRCS = main.c init_arguments.c init_threads.c monitor.c utils1.c utils2.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo "No objects to clean.."

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
