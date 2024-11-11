#include "main.h"

/* Define global variables */
int player_turn;
int available[SIZE];
int available_counter;
char xo[SIZE];

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	intro();
	menuscreen();

	int mode = 0;
	struct single_player sp_stats = {0, 0, 0, 0, ""};
	struct multiplayer mp_stats = {0, 0, "", ""};
	char board[3][3];
	struct game_record current_game;
	const char *history_file = "game_history.csv";
	struct game_record history_records[MAX_GAMES];
	int history_count = 0;

	// Seed the random number generator once
	srand(time(NULL));

	// Load game board, leaderboard, and game history
	load_game_board(board, "game_board.csv");
	load_leaderboard(&sp_stats, &mp_stats, "leaderboard.csv");
	load_game_history(history_records, &history_count, history_file);

	while (1)
	{
		menuscreen(); // Replaced display_home_page() with menuscreen()
		if (scanf("%d", &mode) != 1)
		{
			printf("Invalid input. Try again.\n");
			while (getchar() != '\n')
				; // Clear input buffer
			continue;
		}

		if (mode == 1 || mode == 2) // Single Player Easy or Hard
		{
			if (mode == 1)
			{
				// Single Player Easy
				// No additional setup needed
			}
			else
			{
				// Single Player Hard
				// No additional setup needed
			}

			printf("Enter your name: ");
			scanf("%s", sp_stats.name);

			// Set current game record
			current_game.game_type = GAME_TYPE_SINGLE;
			strcpy(current_game.player_name, sp_stats.name);
			strcpy(current_game.player2_name, "Computer");
		}
		else if (mode == 3) // Multiplayer
		{
			printf("Enter name of Player 1: ");
			scanf("%s", mp_stats.name1);
			printf("Enter name of Player 2: ");
			scanf("%s", mp_stats.name2);

			// Set current game record
			current_game.game_type = GAME_TYPE_MULTIPLAYER;
			strcpy(current_game.player_name, mp_stats.name1);
			strcpy(current_game.player2_name, mp_stats.name2);
		}
		else if (mode == 4) // View Leaderboard
		{
			display_leaderboard(sp_stats, mp_stats);
			continue;
		}
		else if (mode == 5) // Hangman Easy
		{
			hangman_easy();
			continue;
		}
		else if (mode == 6) // Hangman Hard
		{
			hangman_hard();
			continue;
		}
		else if (mode == 7) // Exit
		{
			// Save game board, leaderboard, and game history before exiting
			save_game_board(board, "game_board.csv");
			save_leaderboard(sp_stats, mp_stats, "leaderboard.csv");
			// No new games to save
			printf("Thank you for playing!\n");
			break;
		}
		else
		{
			printf("Invalid choice. Try again.\n");
			continue;
		}

		initialize_game();
		display_board();

		while (check_winner() == -1)
		{
			if (mode == 3) // Multiplayer
			{
				if (player_turn)
					player_move(mp_stats.name1);
				else
					player_move(mp_stats.name2);
			}
			else if (mode == 1 || mode == 2) // Single Player
			{
				if (player_turn)
				{
					player_move(sp_stats.name);
				}
				else
				{
					if (mode == 1)
						computer_move_easy();
					else
						computer_move_hard();
				}
			}
			display_board();
		}

		int result = check_winner();
		if (result == 1)
		{
			if (mode == 1 || mode == 2)
			{
				printf("%s wins!\n", sp_stats.name);
				if (mode == 1)
					sp_stats.wins_easy++;
				else
					sp_stats.wins_hard++;
				current_game.result = 1;
			}
			else
			{
				printf("%s wins!\n",
					   player_turn ? mp_stats.name2 : mp_stats.name1);
				if (player_turn)
					mp_stats.player2_wins++;
				else
					mp_stats.player1_wins++;
				current_game.result = player_turn ? 2 : 1;
			}
		}
		else if (result == 2)
		{
			if (mode == 1 || mode == 2)
			{
				printf("Computer wins!\n");
				if (mode == 1)
					sp_stats.computer_wins_easy++;
				else
					sp_stats.computer_wins_hard++;
				current_game.result = 2;
			}
			else
			{
				printf("%s wins!\n",
					   player_turn ? mp_stats.name2 : mp_stats.name1);
				if (player_turn)
					mp_stats.player2_wins++;
				else
					mp_stats.player1_wins++;
				current_game.result = player_turn ? 2 : 1;
			}
		}
		else
		{
			printf("It's a draw!\n");
			current_game.result = 0;
		}

		// Save the current game to history
		save_game_history(current_game, history_file);
		// Optionally, add to history_records array
		if (history_count < MAX_GAMES)
		{
			history_records[history_count++] = current_game;
		}

		// Save game board and leaderboard
		save_game_board(board, "game_board.csv");
		save_leaderboard(sp_stats, mp_stats, "leaderboard.csv");
	}
	return 0;
}
