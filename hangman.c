#include "main.h"

/**
 * draw_hangman - Displays the hangman figure based on remaining attempts
 * @attempts_left: Number of attempts remaining
 */
void draw_hangman(int attempts_left)
{
	printf("\n");
	printf("  +---+\n");
	printf("  |   |\n");
	printf("  %c   |\n", attempts_left < 6 ? 'O' : ' ');
	printf(" %c%c%c  |\n",
		   attempts_left < 4 ? '/' : ' ',
		   attempts_left < 5 ? '|' : ' ',
		   attempts_left < 3 ? '\\' : ' ');
	printf(" %c %c  |\n",
		   attempts_left < 2 ? '/' : ' ',
		   attempts_left < 1 ? '\\' : ' ');
	printf("      |\n");
	printf("=========\n\n");
}

/**
 * display_guessed_letters - Displays the letters that have been guessed
 * @guessed_letters: Array of guessed letters
 * @count: Number of guessed letters
 */
void display_guessed_letters(char guessed_letters[], int count)
{
	printf("Guessed Letters: ");
	for (int i = 0; i < count; i++)
	{
		printf("%c ", guessed_letters[i]);
	}
	printf("\n\n");
}

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
	char guessed_letters[26];
	int guessed_count = 0;

	// Initialize guess with underscores
	for (i = 0; i < word_length; i++)
		guess[i] = '_';
	guess[word_length] = '\0';

	printf("\n=== Hangman Easy ===\n");
	draw_hangman(attempts);
	display_guessed_letters(guessed_letters, guessed_count);

	while (attempts > 0 && correct < word_length)
	{
		printf("Word: %s\n", guess);
		printf("Attempts left: %d\n", attempts);
		display_guessed_letters(guessed_letters, guessed_count);
		printf("Enter a letter: ");
		char letter;
		if (scanf(" %c", &letter) != 1)
		{
			printf("Invalid input. Try again.\n");
			while (getchar() != '\n')
				; // Clear input buffer
			continue;
		}

		// Convert to lowercase for consistency
		letter = tolower(letter);

		// Check if letter has already been guessed
		int already_guessed = 0;
		for (i = 0; i < guessed_count; i++)
		{
			if (guessed_letters[i] == letter)
			{
				already_guessed = 1;
				break;
			}
		}
		if (already_guessed)
		{
			printf("You have already guessed that letter. Try another.\n\n");
			continue;
		}

		guessed_letters[guessed_count++] = letter;

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
		else
		{
			printf("Good guess!\n");
		}

		draw_hangman(attempts);
		printf("\n");
	}

	if (correct == word_length)
		printf("Congratulations! You guessed the word: %s\n", word);
	else
	{
		printf("Game Over! The word was: %s\n", word);
		draw_hangman(0); // Final hangman state
	}
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
	char guessed_letters[26];
	int guessed_count = 0;

	// Initialize guess with underscores
	for (i = 0; i < word_length; i++)
		guess[i] = '_';
	guess[word_length] = '\0';

	printf("\n=== Hangman Hard ===\n");
	draw_hangman(attempts);
	display_guessed_letters(guessed_letters, guessed_count);

	while (attempts > 0 && correct < word_length)
	{
		printf("Word: %s\n", guess);
		printf("Attempts left: %d\n", attempts);
		display_guessed_letters(guessed_letters, guessed_count);
		printf("Enter a letter: ");
		char letter;
		if (scanf(" %c", &letter) != 1)
		{
			printf("Invalid input. Try again.\n");
			while (getchar() != '\n')
				; // Clear input buffer
			continue;
		}

		// Convert to lowercase for consistency
		letter = tolower(letter);

		// Check if letter has already been guessed
		int already_guessed = 0;
		for (i = 0; i < guessed_count; i++)
		{
			if (guessed_letters[i] == letter)
			{
				already_guessed = 1;
				break;
			}
		}
		if (already_guessed)
		{
			printf("You have already guessed that letter. Try another.\n\n");
			continue;
		}

		guessed_letters[guessed_count++] = letter;

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
		else
		{
			printf("Good guess!\n");
		}

		draw_hangman(attempts);
		printf("\n");
	}

	if (correct == word_length)
		printf("Congratulations! You guessed the word: %s\n", word);
	else
	{
		printf("Game Over! The word was: %s\n", word);
		draw_hangman(0); // Final hangman state
	}
}
