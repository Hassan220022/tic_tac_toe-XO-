#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * hangman_easy - Implements the easy mode of Hangman game
 */
void hangman_easy(void)
{
	const char *word = "easy"; // Simple word for easy mode
	int word_length = strlen(word);
	char guess[word_length + 1];
	int attempts = 6;
	int i;
	int correct = 0;

	// Initialize guess with underscores
	for (i = 0; i < word_length; i++)
		guess[i] = '_';
	guess[word_length] = '\0';

	printf("\n=== Hangman Easy ===\n");
	while (attempts > 0 && correct < word_length)
	{
		printf("Word: %s\n", guess);
		printf("Attempts left: %d\n", attempts);
		printf("Enter a letter: ");
		char letter;
		scanf(" %c", &letter);

		int found = 0;
		for (i = 0; i < word_length; i++)
		{
			if (word[i] == letter && guess[i] == '_')
			{
				guess[i] = letter;
				correct++;
				found = 1;
			}
		}

		if (!found)
		{
			printf("Wrong guess!\n");
			attempts--;
		}
	}

	if (correct == word_length)
		printf("Congratulations! You guessed the word: %s\n", word);
	else
		printf("Game Over! The word was: %s\n", word);
}

/**
 * hangman_hard - Implements the hard mode of Hangman game
 */
void hangman_hard(void)
{
	const char *word = "hard"; // More complex word for hard mode
	int word_length = strlen(word);
	char guess[word_length + 1];
	int attempts = 6;
	int i;
	int correct = 0;

	// Initialize guess with underscores
	for (i = 0; i < word_length; i++)
		guess[i] = '_';
	guess[word_length] = '\0';

	printf("\n=== Hangman Hard ===\n");
	while (attempts > 0 && correct < word_length)
	{
		printf("Word: %s\n", guess);
		printf("Attempts left: %d\n", attempts);
		printf("Enter a letter: ");
		char letter;
		scanf(" %c", &letter);

		int found = 0;
		for (i = 0; i < word_length; i++)
		{
			if (word[i] == letter && guess[i] == '_')
			{
				guess[i] = letter;
				correct++;
				found = 1;
			}
		}

		if (!found)
		{
			printf("Wrong guess!\n");
			attempts--;
		}
	}

	if (correct == word_length)
		printf("Congratulations! You guessed the word: %s\n", word);
	else
		printf("Game Over! The word was: %s\n", word);
}
