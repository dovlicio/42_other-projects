NAME1 = client
NAME2 = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LFLAGS = -L$(LIBFT_DIR) -lft

SRC1 = client.c
SRC2 = server.c

all: $(NAME1) $(NAME2)

$(NAME1): $(SRC1)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(NAME2): $(SRC2)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
