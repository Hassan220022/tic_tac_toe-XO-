#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

/* Structures for player statistics */
/**
 * struct single_player - Single player statistics
 * @wins_easy: Number of wins in easy mode
 * @wins_hard: Number of wins in hard mode
 * @computer_wins_easy: Computer wins in easy mode
 * @computer_wins_hard: Computer wins in hard mode
 * @name: Player's name
 */
struct single_player
{
	int wins_easy;
	int wins_hard;
	int computer_wins_easy;
	int computer_wins_hard;
	char name[50];
};

/**
 * struct multiplayer - Multiplayer statistics
 * @player1_wins: Wins for player 1
 * @player2_wins: Wins for player 2
 * @name1: Name of player 1
 * @name2: Name of player 2
 */
struct multiplayer
{
	int player1_wins;
	int player2_wins;
	char name1[50];
	char name2[50];
};

/* Structure for game history */
#define GAME_TYPE_SINGLE 1
#define GAME_TYPE_MULTIPLAYER 2
#define MAX_GAMES 1000

/**
 * struct game_record - Represents a single game record
 * @game_type: 1 for Single Player, 2 for Multiplayer
 * @player_name: Player's name (Single Player) or Player 1's name (Multiplayer)
 * @player2_name: Player 2's name (Multiplayer) or empty string (Single Player)
 * @result: 1 if player 1 wins, 2 if player 2/computer wins, 0 if draw
 */
struct game_record
{
	int game_type;
	char player_name[50];
	char player2_name[50];
	int result;
};

/* Global variables */
extern int player_turn;
extern int available[SIZE];
extern int available_counter;
extern char xo[SIZE];

/* Function prototypes */
void initialize_game(void);
void display_board(void);
int check_winner(void);
void player_move(char *player_name);
void computer_move_easy(void);
void computer_move_hard(void);
void menuscreen(void);
void display_leaderboard(struct single_player sp_stats,
						 struct multiplayer mp_stats);
void save_game_board(char board[3][3], const char *filename);
void load_game_board(char board[3][3], const char *filename);

/* New function prototypes for leaderboard */
void save_leaderboard(struct single_player sp_stats,
					  struct multiplayer mp_stats,
					  const char *filename);
void load_leaderboard(struct single_player *sp_stats,
					  struct multiplayer *mp_stats,
					  const char *filename);

/* New function prototypes for Minimax */
int minimax(char board[SIZE], int depth, int is_maximizing, int alpha, int beta);
int check_winner_board(char board[SIZE]);

/* Function prototypes for game history */
void save_game_history(struct game_record record, const char *filename);
void load_game_history(struct game_record *records, int *count, const char *filename);

/* Function prototypes for Hangman */
void hangman_easy(void);
void hangman_hard(void);

#endif /* MAIN_H */
