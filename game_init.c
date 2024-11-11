#include "main.h"

/**
 * initialize_game - Initializes the game state
 */
void initialize_game(void)
{
	int i;

	for (i = 0; i < SIZE; i++)
	{
		available[i] = 1;
		xo[i] = '1' + i;
	}
	available_counter = SIZE;
	player_turn = 1;
}

/**
 * display_board - Displays the current game board
 */
void display_board(void)
{
	printf("\n");
	printf(" %c | %c | %c\n", xo[0], xo[1], xo[2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", xo[3], xo[4], xo[5]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n\n", xo[6], xo[7], xo[8]);
}
