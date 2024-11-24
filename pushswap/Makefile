CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LFLAGS = -L$(LIBFT_DIR) -lft
NAME = push_swap
DIR1 = basic_functions
DIR2 = handling_arguments
DIR3 = sorting

SRC = \
	main.c $(DIR1)/push_functions.c $(DIR1)/rotate_first.c $(DIR1)/rotate_last.c \
	$(DIR1)/swap_functions.c $(DIR2)/errors.c $(DIR2)/handling_arguments.c \
	$(DIR3)/sorting_small.c $(DIR3)/sorting_small_utils.c $(DIR3)/sort_big.c \
	$(DIR3)/execute_from_a.c $(DIR3)/execute_from_b.c $(DIR3)/calculate_moves.c \
	$(DIR3)/sorting_big_utils.c

all: $(NAME)

$(NAME): $(SRC)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
