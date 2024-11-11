#include "main.h"

/**
 * check_winner - Checks for a winner or a draw
 *
 * Return: 1 if player 1 wins, 2 if player 2/computer wins,
 *         0 if draw, -1 if game continues
 */
int check_winner(void)
{
	int i;
	int win_combinations[8][3] = {
		{0, 1, 2}, /* Rows */
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6}, /* Columns */
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8}, /* Diagonals */
		{2, 4, 6}};

	for (i = 0; i < 8; i++)
	{
		if (xo[win_combinations[i][0]] == xo[win_combinations[i][1]] &&
			xo[win_combinations[i][1]] == xo[win_combinations[i][2]])
		{
			if (xo[win_combinations[i][0]] == 'X')
				return (1);
			else if (xo[win_combinations[i][0]] == 'O')
				return (2);
		}
	}
	if (available_counter == 0)
		return (0); /* Draw */
	return (-1);	/* Game continues */
}
