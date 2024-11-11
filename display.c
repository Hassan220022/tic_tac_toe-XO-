#include "main.h"

/**
 * display_leaderboard - Displays the game leaderboard in a robust format
 * @sp_stats: Single player statistics
 * @mp_stats: Multiplayer statistics
 */
void display_leaderboard(struct single_player sp_stats,
						 struct multiplayer mp_stats)
{
	printf("\n=========== Leaderboard ===========\n");

	printf("\n--- Single Player ---\n");
	printf("Player Name         | Wins (Easy) | Wins (Hard)\n");
	printf("-------------------------------------------------\n");
	printf("%-19s | %-11d | %-11d\n",
		   sp_stats.name[0] ? sp_stats.name : "Player",
		   sp_stats.wins_easy,
		   sp_stats.wins_hard);
	printf("Computer Wins (Easy): %d\n", sp_stats.computer_wins_easy);
	printf("Computer Wins (Hard): %d\n", sp_stats.computer_wins_hard);

	printf("\n--- Multiplayer ---\n");
	printf("Player 1 Name       | Wins\n");
	printf("---------------------------------\n");
	printf("%-19s | %-5d\n",
		   mp_stats.name1[0] ? mp_stats.name1 : "Player 1",
		   mp_stats.player1_wins);
	printf("%-19s | %-5d\n",
		   mp_stats.name2[0] ? mp_stats.name2 : "Player 2",
		   mp_stats.player2_wins);

	printf("\n===================================\n\n");
}

/**
 * display_game_history - Displays all recorded game histories
 * @records: Array of game records
 * @count: Number of game records
 */
void display_game_history(struct game_record *records, int count)
{
	printf("\n=========== Game History ===========\n");

	for (int i = 0; i < count; i++)
	{
		printf("Game %d:\n", i + 1);
		if (records[i].game_type == GAME_TYPE_SINGLE)
		{
			printf("  Type: Single Player\n");
			printf("  Player: %s\n", records[i].player_name);
			printf("  Computer: Computer\n");
		}
		else if (records[i].game_type == GAME_TYPE_MULTIPLAYER)
		{
			printf("  Type: Multiplayer\n");
			printf("  Player 1: %s\n", records[i].player_name);
			printf("  Player 2: %s\n", records[i].player2_name);
		}

		printf("  Result: ");
		if (records[i].result == 1)
			printf("Player 1 wins\n");
		else if (records[i].result == 2)
			printf("Player 2/Computer wins\n");
		else
			printf("Draw\n");
		printf("\n");
	}

	printf("===================================\n\n");
}

/**
 * menuscreen - Displays the main menu with all options including Leaderboard
 */
void menuscreen(void) // the start menu
{
	printf("\n\nEnter the corresponding number to the program you want to run: ");
	printf("\n\n \n  ------------------------------------\n |");
	printf(" 1. Single Player (Easy)\t\t      |");
	printf(" \n |------------------------------------|\n |");
	printf(" 2. Single Player (Hard)\t\t      |");
	printf(" \n |------------------------------------|\n |");
	printf(" 3. Multiplayer\t\t      |");
	printf(" \n |------------------------------------|\n |");
	printf(" 4. View Leaderboard\t\t      |"); // Ensured View Leaderboard is present
	printf(" \n |------------------------------------|\n |");
	printf(" 5. Hangman (Easy)\t\t      |");
	printf(" \n |------------------------------------|\n |");
	printf(" 6. Hangman (Hard)\t\t      |");
	printf(" \n |------------------------------------|\n |");
	printf(" 7. Exit\t\t\t      |");
	printf(" \n  ------------------------------------\n");
}

void intro(void)
{
	printf("MADE BY CEO and cofounder HAASSAN MIKAWI 20104451\n\t\t\t\tMazen Ibrahim Mohamed 20104387\n\n\n");
	printf("MADE BY CEO and cofounder HAASSAN MIKAWI 20104451\n\t\t\t\tMazen Ibrahim Mohamed 20104387\n\n\n");
}
