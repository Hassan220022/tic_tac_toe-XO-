#include "main.h"

/**
 * save_game_board - Saves the game board to a CSV file
 * @board: 3x3 game board array
 * @filename: Name of the file to save the board
 */
void save_game_board(char board[3][3], const char *filename)
{
	FILE *file = fopen(filename, "w");
	if (file == NULL)
	{
		printf("Error saving game board.\n");
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		fprintf(file, "%c,%c,%c\n", board[i][0], board[i][1], board[i][2]);
	}

	fclose(file);
}

/**
 * load_game_board - Loads the game board from a CSV file
 * @board: 3x3 game board array
 * @filename: Name of the file to load the board from
 */
void load_game_board(char board[3][3], const char *filename)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		// Initialize board if file doesn't exist
		char initial[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				board[i][j] = initial[i][j];
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		fscanf(file, " %c,%c,%c", &board[i][0], &board[i][1], &board[i][2]);
	}

	fclose(file);
}

/**
 * save_leaderboard - Saves player statistics to a CSV file
 * @sp_stats: Single player statistics
 * @mp_stats: Multiplayer statistics
 * @filename: Name of the file to save the leaderboard
 */
void save_leaderboard(struct single_player sp_stats,
					  struct multiplayer mp_stats,
					  const char *filename)
{
	FILE *file = fopen(filename, "w");
	if (file == NULL)
	{
		printf("Error saving leaderboard.\n");
		return;
	}

	// Save Single Player Stats
	fprintf(file, "Single Player,%s,%d,%d,%d,%d\n",
			sp_stats.name,
			sp_stats.wins_easy,
			sp_stats.wins_hard,
			sp_stats.computer_wins_easy,
			sp_stats.computer_wins_hard);

	// Save Multiplayer Stats
	fprintf(file, "Multiplayer,%s,%d,%s,%d\n",
			mp_stats.name1,
			mp_stats.player1_wins,
			mp_stats.name2,
			mp_stats.player2_wins);

	fclose(file);
}

/**
 * load_leaderboard - Loads player statistics from a CSV file
 * @sp_stats: Pointer to single player statistics structure
 * @mp_stats: Pointer to multiplayer statistics structure
 * @filename: Name of the file to load the leaderboard from
 */
void load_leaderboard(struct single_player *sp_stats,
					  struct multiplayer *mp_stats,
					  const char *filename)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		// Initialize with default values if leaderboard doesn't exist
		strcpy(sp_stats->name, "Player");
		sp_stats->wins_easy = 0;
		sp_stats->wins_hard = 0;
		sp_stats->computer_wins_easy = 0;
		sp_stats->computer_wins_hard = 0;

		strcpy(mp_stats->name1, "Player 1");
		mp_stats->player1_wins = 0;
		strcpy(mp_stats->name2, "Player 2");
		mp_stats->player2_wins = 0;
		return;
	}

	char mode[20];
	// Load Single Player Stats
	if (fscanf(file, "%[^,],%[^,],%d,%d,%d,%d\n",
			   mode,
			   sp_stats->name,
			   &sp_stats->wins_easy,
			   &sp_stats->wins_hard,
			   &sp_stats->computer_wins_easy,
			   &sp_stats->computer_wins_hard) != 6)
	{
		printf("Error loading single player stats.\n");
	}

	// Load Multiplayer Stats
	if (fscanf(file, "%[^,],%[^,],%d,%[^,],%d\n",
			   mode,
			   mp_stats->name1,
			   &mp_stats->player1_wins,
			   mp_stats->name2,
			   &mp_stats->player2_wins) != 5)
	{
		printf("Error loading multiplayer stats.\n");
	}

	fclose(file);
}

/**
 * save_game_history - Saves a single game record to a CSV file
 * @record: The game record to save
 * @filename: Name of the file to save the game history
 */
void save_game_history(struct game_record record, const char *filename)
{
    FILE *file = fopen(filename, "a"); // Append mode
    if (file == NULL)
    {
        printf("Error saving game history.\n");
        return;
    }

    if (record.game_type == GAME_TYPE_SINGLE)
    {
        // Single Player: Game Type, Player Name, Computer, Result
        fprintf(file, "Single Player,%s,,%d\n",
                record.player_name,
                record.result);
    }
    else if (record.game_type == GAME_TYPE_MULTIPLAYER)
    {
        // Multiplayer: Game Type, Player 1, Player 2, Result
        fprintf(file, "Multiplayer,%s,%s,%d\n",
                record.player_name,
                record.player2_name,
                record.result);
    }
    else if (record.game_type == 3) // Hangman Easy
    {
        // Hangman Easy: Game Type, Player Name, Difficulty, Result
        fprintf(file, "Hangman,Easy,%s,%d\n",
                record.player_name,
                record.result);
    }
    else if (record.game_type == 4) // Hangman Hard
    {
        // Hangman Hard: Game Type, Player Name, Difficulty, Result
        fprintf(file, "Hangman,Hard,%s,%d\n",
                record.player_name,
                record.result);
    }

    fclose(file);
}

/**
 * load_game_history - Loads all game records from a CSV file
 * @records: Array to store loaded game records
 * @count: Pointer to store the number of loaded records
 * @filename: Name of the file to load the game history from
 */
void load_game_history(struct game_record *records, int *count, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        // No game history exists
        *count = 0;
        return;
    }

    *count = 0;
    while (*count < MAX_GAMES && !feof(file))
    {
        char game_type_str[20];
        char difficulty[10];
        char player_name[50];
        int result;

        // Read a line and parse it
        if (fscanf(file, "%19[^,],%9[^,],%49[^,],%d\n",
                   game_type_str,
                   difficulty,
                   player_name,
                   &result) == 4)
        {
            if (strcmp(game_type_str, "Hangman") == 0)
            {
                if (strcmp(difficulty, "Easy") == 0)
                    records[*count].game_type = 3; // Hangman Easy
                else if (strcmp(difficulty, "Hard") == 0)
                    records[*count].game_type = 4; // Hangman Hard
                strcpy(records[*count].player_name, player_name);
                strcpy(records[*count].player2_name, ""); // Not applicable
                records[*count].result = result;
            }
            else
            {
                // Existing game types
                // ...existing parsing code...
            }
            (*count)++;
        }
        else
        {
            // Handle malformed lines
            break;
        }
    }

    fclose(file);
}
