CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = main.c game_init.c game_logic.c player_actions.c display.c save_load.c
OBJ = $(SRC:.c=.o)
NAME = xo_game

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c main.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re