#include "main.h"

/**
 * player_move - Handles a player's move
 * @player_name: Name of the player making the move
 */
void player_move(char *player_name)
{
	int move;

	printf("%s's turn (%c). Enter your move (1-9): ",
		   player_name, player_turn ? 'X' : 'O');
	if (scanf("%d", &move) != 1)
	{
		printf("Invalid input. Try again.\n");
		while (getchar() != '\n')
			/* Clear input buffer */
			player_move(player_name);
		return;
	}

	move--;
	if (move >= 0 && move < SIZE && available[move])
	{
		xo[move] = player_turn ? 'X' : 'O';
		available[move] = 0;
		available_counter--;
		player_turn = !player_turn;
	}
	else
	{
		printf("Invalid move. Try again.\n");
		while (getchar() != '\n')
			/* Clear input buffer */
			player_move(player_name);
	}
}

/**
 * computer_move_easy - Handles the computer's move in easy mode
 */
void computer_move_easy(void)
{
	int move;

	move = rand() % SIZE;
	while (!available[move])
	{
		move = rand() % SIZE;
	}
	xo[move] = 'O';
	available[move] = 0;
	available_counter--;
	player_turn = !player_turn;
	printf("Computer chose position %d\n", move + 1);
}

/**
 * computer_move_hard - Handles the computer's move in hard mode using Minimax algorithm
 */
void computer_move_hard(void)
{
	int best_score = -1000;
	int move = -1;
	int i;
	for (i = 0; i < SIZE; i++)
	{
		if (available[i])
		{
			/* Make the move */
			xo[i] = 'O';
			available[i] = 0;
			available_counter--;

			/* Compute evaluation function for this move */
			int score = minimax(xo, 0, 0, -1000, 1000);

			/* Undo the move */
			xo[i] = '1' + i;
			available[i] = 1;
			available_counter++;

			if (score > best_score)
			{
				best_score = score;
				move = i;
			}
		}
	}

	if (move != -1)
	{
		xo[move] = 'O';
		available[move] = 0;
		available_counter--;
		player_turn = !player_turn;
		printf("Computer chose position %d\n", move + 1);
	}
	else
	{
		/* No moves left, should be a draw */
	}
}

/**
 * minimax - Minimax algorithm implementation with alpha-beta pruning
 * @board: Current game board as a one-dimensional array
 * @depth: Current depth in the game tree
 * @is_maximizing: Flag indicating if the current move is maximizing or minimizing
 * @alpha: Alpha value for pruning
 * @beta: Beta value for pruning
 *
 * Return: The best score for the current player
 */
int minimax(char board[SIZE], int depth, int is_maximizing, int alpha, int beta)
{
	int winner = check_winner_board(board);
	if (winner == 2) /* Computer wins */
		return (10 - depth);
	if (winner == 1) /* Player wins */
		return (depth - 10);
	if (winner == 0) /* Draw */
		return (0);

	if (is_maximizing)
	{
		int max_eval = -1000;
		int i;
		for (i = 0; i < SIZE; i++)
		{
			if (board[i] != 'X' && board[i] != 'O')
			{
				char original = board[i];
				board[i] = 'O';
				int eval = minimax(board, depth + 1, 0, alpha, beta);
				board[i] = original;
				if (eval > max_eval)
					max_eval = eval;
				if (eval > alpha)
					alpha = eval;
				if (beta <= alpha)
					break;
			}
		}
		return (max_eval);
	}
	else
	{
		int min_eval = 1000;
		int i;
		for (i = 0; i < SIZE; i++)
		{
			if (board[i] != 'X' && board[i] != 'O')
			{
				char original = board[i];
				board[i] = 'X';
				int eval = minimax(board, depth + 1, 1, alpha, beta);
				board[i] = original;
				if (eval < min_eval)
					min_eval = eval;
				if (eval < beta)
					beta = eval;
				if (beta <= alpha)
					break;
			}
		}
		return (min_eval);
	}
}

/**
 * check_winner_board - Checks for a winner on a given board
 * @board: The game board as a one-dimensional array to check
 *
 * Return: 1 if player wins, 2 if computer wins, 0 if draw, -1 if game continues
 */
int check_winner_board(char board[SIZE])
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
		if (board[win_combinations[i][0]] == board[win_combinations[i][1]] &&
			board[win_combinations[i][1]] == board[win_combinations[i][2]])
		{
			if (board[win_combinations[i][0]] == 'X')
				return (1);
			else if (board[win_combinations[i][0]] == 'O')
				return (2);
		}
	}
	/* Check for draw */
	int available_moves = 0;
	for (i = 0; i < SIZE; i++)
	{
		if (board[i] != 'X' && board[i] != 'O')
		{
			available_moves++;
		}
	}
	if (available_moves == 0)
		return (0); /* Draw */
	return (-1);	/* Game continues */
}
