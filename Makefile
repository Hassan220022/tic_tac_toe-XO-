CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = main.c game_init.c game_logic.c player_actions.c display.c save_load.c hangman.c
OBJ = $(SRC:.c=.o)
NAME = xo_game

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c main.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	clear

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all

git: fclean
	rm *.csv
	git add .
	git commit -m "update"
	git push

.PHONY: all clean fclean re