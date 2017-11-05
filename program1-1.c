//Rong Zheng , 2/9/2017, program 1
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <ctype.h> 
#define MAXGUESSES 5
int getgame(void); //get how many games user want play
char GetGuess(void); //get guess from user
int CompareCharacters(char letterFromFile, char guessFromUser); //compare the guess to anwer
void PlayOneRound(char letterFromFile); //play 1 round
void LetterGuessGameRules(void); //print welcome and rule
int main()
{
	//declare additional variables
	//declare FILE pointer 
	int numGames, i = 0;
	char letter; 
	FILE *letterpointer;
	//letter from file
	//display game rules 
	LetterGuessGameRules();
	//Ask and get number of games to play 
	numGames = getgame();
	//connect to the file HINT: use fopen 
	letterpointer = fopen("letters.txt", "r");
	//this for loop will allow the player to play more than one game
	//without recompiling 
	for (i = 0; i < numGames; i++)
	{
		fscanf(letterpointer, " %c", &letter);
		printf("***********************************************\n\n");
		printf("Ready to play game %d", i+1);
		//get a solution letter from file - use fscanf 
		//change the solution to uppercase 
		//print the solution back onto the screen to test
		//call the GuessTheLetter function and pass it the solution
		PlayOneRound(toupper(letter));
	}

	//close file pointer 
	fclose(letterpointer);
	if (i >= numGames)
	{
		printf("\nThank you for Playing, GoodBye.\n");
		scanf("%d", &numGames); //keep program from closing before say goodbye
	}
	return 0;
}
//this function provides instructions to the user on how to play the game
void LetterGuessGameRules(void)
{
	printf("Welcome to the Letter Guessing Game\n\n");
	printf("First, you will enter the number of games you want to play(1 - 10 games)\n");
	printf("For each game you will have 5 chances to guess each letter\nLet's begin:\n\n");
}
//get how many games user want play
int getgame(void)
{
	int game;
	printf("How many games you want play(1-10)\n");
	scanf("%d", &game);
	return game;
}
//this function prompts the player to make a guess and returns that guess 
//this function is called from inside the PlayOneRound ( ) function described above
char GetGuess(void)
{
	char guess;
	printf("Please Enter your guess\n");
	scanf(" %c", &guess);
	return guess;
}
//this function takes two arguments, the guess from the player 
//and the solution letter from the file. 
//The function returns 1 if the guess matches the solution and returns a 0 if they do not match 
//This function also lets the user know if the guess comes alphabetically before or after the solution
int CompareCharacters(char letterFromFile, char guessFromUser)
{
	if (letterFromFile == guessFromUser)
	{
		return 1;
	}
	else if (guessFromUser > letterFromFile)
	{
		printf("The solution comes BEFORE your guess (%c)\n", guessFromUser);
		return 0;
	}
	else
	{
		printf("The solution comes AFTER your guess (%C)\n", guessFromUser);
		return 0;
	}
}
//this function runs one game. 
//input: character from the file 
//void return type 
//all other functions to Play one round of a game 
//are called from within the GuessTheLetter function 
void PlayOneRound(char letterFromFile)
{
	int win = 0;
	int numGuesses = 0;
	//declare additional variables
	char guess, guessu;
	while (numGuesses < MAXGUESSES && win == 0)
	{
		printf("\n----------------------------------------\n");
		printf("Getting guess number %d\n", numGuesses+1);
		//get a guess from the user  by calling the GetTheGuess function 
		guess = GetGuess();
		//change the guess to uppercase   
		guessu = toupper(guess);
		//win = call the function to compare the guess with the solution
		win = CompareCharacters(letterFromFile, guessu);
		numGuesses++; //count the number of guesses so far
		
	}
	//use conditions to let the user know if they won or lost the round of the game
	if (win == 1)
	{
		printf("\nThe solution and the guess are the same (%c) \n\n     And you Won !!!\n", letterFromFile);
	}
	if (numGuesses == MAXGUESSES && win == 0)
	{
		printf("\nSORRY, you did not win this round\n\n The letter was (%c)\n", letterFromFile);
	}
	
}