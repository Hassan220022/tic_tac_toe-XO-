
#ifndef GAME_RECORD_H
#define GAME_RECORD_H

#define GAME_TYPE_SINGLE 1
#define GAME_TYPE_MULTIPLAYER 2
#define GAME_TYPE_HANGMAN_EASY 3
#define GAME_TYPE_HANGMAN_HARD 4

struct game_record
{
    int game_type;
    char player_name[50];
    char player2_name[50];
    int result;
};

#endif /* GAME_RECORD_H */