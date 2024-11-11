#include "main.h"

/**
 * display_home_page - Displays the game's home page with updated options
 */
void display_home_page(void)
{
	printf("******************************************\n");
	printf("*            Welcome to XO Game          *\n");
	printf("******************************************\n");
	printf("\n");
	printf("Select an option:\n");
	printf("1. Single Player (Easy)\n");
	printf("2. Single Player (Hard)\n");
	printf("3. Multiplayer\n");
	printf("4. View Leaderboard\n");
	printf("5. Exit\n");
	printf("\n");
	printf("Enter your choice: ");
}

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
