//Rong Zheng, 4/4/2017, program 3

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <ctype.h> 
#include <string.h> //strcmp, //strlen
#define WSIZE 30 
//Determines if the player wants to play again
void Quit(char *againPtr);
//Displays instructions
void Rules();
//initializes the word to be guessed to *** based on word size 
void InitializeWord(char starWord[], int wordsize);
//play a round of the game, returns a 1 if the user wins and a 0 if the user did not win
int PlayOneRound(char solutionWord[], char starWord[]);
void GetLetter(char *letterPtr);
//compares two char arrays returns 1 if match, 0 if dont match 
int CompareArrays(char wordGuess[], char solutionWord[]);
//notifies the user if they won or lost 
void WonLost(char solutionWord[], int win);
//replaces the star with the letter guessed
//returns a 1 if the letter is in the word, returns a 0 if the letter 
//is not in the word
int PlaceLetter(char solutionWord[], char starWord[], char target);
//changes a word to upper or lower case 
void ChangeCase(char word[]);
//draws the hangman  
void DrawHangman(int num);
int main()
{
	FILE *wfile;
	char word[WSIZE] = "hamburger";
	char star[WSIZE];
	char again;
	int len;
	int win;
	Rules();
	wfile = fopen("hangmanWords.txt", "r");
	do {
		fscanf(wfile, " %s", &word);
		ChangeCase(word);
		len = strlen(word);
		InitializeWord(star, len);
		printf("Here are the word %s", star);
		win = PlayOneRound(word, star);
		WonLost(word, win);
		Quit(&again);
	} while (again == 'Y');
	printf("\nGoodBye\n");
	scanf("%d", &len); //prevent app from closing
	return 0;
}
void Quit(char *againPtr)
{
	char lower;
	printf("\n\n");
	printf("<<You want play again? y or n>>\n");
	scanf(" %c", &lower);
	*againPtr = toupper(lower);
}
void ChangeCase(char word[])
{
	int len = strlen(word);
	int i;
	for (i = 0; i<len; i++)
	{
		word[i] = toupper(word[i]);
	}
}
void InitializeWord(char starWord[], int wordsize)
{
	int i;
	for (i = 0; i < wordsize; i++)
	{
		starWord[i] = '*';
	}
	starWord[wordsize] = '\0';
}
void GetLetter(char *letterPtr)
{
	char letter;
	printf("Enter a letter");
	printf("\n");
	scanf(" %c", &letter);
	*letterPtr = toupper(letter);
	printf("You entered %c", *letterPtr);
	printf("\n");
}
int PlaceLetter(char solutionWord[], char starWord[], char target)
{
	int i, len = strlen(solutionWord);
	int rv = 0;
	for (i = 0; i<len; i++)
	{
		if (solutionWord[i] == target)
		{
			starWord[i] = target;
			rv = 1;
		}
	}
	return rv;
}
void Rules()
{
	printf("WELCOME TO HANGMAN!         \nPlease read the following instructions before you play.         \n-You will be presented with a word to be guessed         \n-Guess letters one at a time         \n-You can have up to six incorrect letter guesses         \n-YOU CAN ONLY GUESS THE WORD IF YOU HAVE MADE A CORRRECT LETTER GUESS!         \n-The game will be OVER when you have guessed the word correctly                 \nor when you have guessed SIX letters incorrectly.         \n\nHAVE FUN!\n\n");
}
int CompareArrays(char wordGuess[], char solutionWord[])
{
	ChangeCase(wordGuess);
	if (strcmp(wordGuess, solutionWord) == 0)
		return 1;
	else return 0;
}
void WonLost(char solutionWord[], int win)
{
	if (win == 1)
	{
		printf("\nCorrect, the solution is %s", solutionWord);
		printf("\nYou win\n");
	}
	else
	{
		printf("\nSorry, you didn't win this round\n");
		printf("The right answer is %s", solutionWord);
	}
}
void DrawHangman(int num)
{
	printf("\n*********");
	if (num == 1)
	{
		printf("\n   ___||____");
		printf("\n  |  o   o  |");
		printf("\n  |    _    |");
		printf("\n  |_________|");
	}
	else if (num == 2)
	{
		printf("\n   ___||____");
		printf("\n  |  o   o  |");
		printf("\n  |    _    |");
		printf("\n  |_________|");
		printf("\n     |    |");
		printf("\n     |    |");
		printf("\n     |_ _ |");

	}
	else if (num == 3)
	{
		printf("\n   ___||____");
		printf("\n  |  o   o  |");
		printf("\n  |    _    |");
		printf("\n  |_________|");
		printf("\n     |    |");
		printf("\n     |    |");
		printf("\n     |_ _ |");
		printf("\n         |");
		printf("\n         |");
		printf("\n         |_");

	}
	else if (num == 4)
	{
		printf("\n   ___||____");
		printf("\n  |  o   o  |");
		printf("\n  |    _    |");
		printf("\n  |_________|");
		printf("\n     |    |");
		printf("\n     |    |");
		printf("\n     |_ _ |");
		printf("\n       | |");
		printf("\n       | |");
		printf("\n      _| |_");
	}
	else if (num == 5)
	{
		printf("\n   ___||____");
		printf("\n  |  o   o  |");
		printf("\n  |    _    |");
		printf("\n  |_________|");
		printf("\n     |    |~~~~~~~");
		printf("\n     |    | ");
		printf("\n     |_ _ |   ");
		printf("\n       | |");
		printf("\n       | |");
		printf("\n      _| |_");
	}
	else
	{
		printf("\n      ||");
		printf("\n      ||");
		printf("\n   ___||____");
		printf("\n  |  X   X  |");
		printf("\n  |    X    |");
		printf("\n  |_________|");
		printf("\n    /|    |~~~~~~~~~");
		printf("\n   / |    |");
		printf("\n  /  |_ _ |");
		printf("\n       | |");
		printf("\n       | |");
		printf("\n      _| |_");
	}
	printf("\n*********\n");
}
int PlayOneRound(char solutionWord[], char starWord[])
{
	char letter;
	char gue[WSIZE];
	char let[WSIZE];
	int ret, comp;
	int i = 0, k = 0; //attempts, i is total guess
	int win = 0;
	do {
		printf("\n~~~~~~~~~~~~~~\n");
		GetLetter(&letter);
		ret = PlaceLetter(solutionWord, starWord, letter);
		let[i] = letter;
		i++;
		let[i] = '\0';
		if (ret == 1)
		{
			printf("Letter %c is in the answer\n", letter);
			printf("Your guess so far %s", starWord);
			printf("\nGuess this word\n");
			scanf(" %s", &gue);
			comp = CompareArrays(gue, solutionWord);
			if (comp == 0)
			{
				printf("\nSorry, %s is not Correct\n", gue);
				printf("\n");
			}
			else {
				return 1;
				k = 10;
			}
		}
		else
		{
			printf("Sorry, %c is not in the word\n", letter);
			k++;
			DrawHangman(k);
			printf("\nYou made %d incorrect guess", k);
			printf("\nYou have %d more letter(s) left\n", 6 - k);
		}
		printf("\nHere are your guessed letter so far %s", let);
		printf("\nYour guess so far %s", starWord);
	} while (k<6);
}