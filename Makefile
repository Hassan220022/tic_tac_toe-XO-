CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -v
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

run: $(NAME)
	./$(NAME)

git: fclean
	rm -f *.csv
	git add .
	git commit -m "update"
	git push
	clear

.PHONY: all clean fclean re