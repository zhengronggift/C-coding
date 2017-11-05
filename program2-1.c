//Rong Zheng, 3/14/2017, program 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define LIMIT 3000
void MakeTransaction(char *againPtr);
void DisplayBalance(double checking, double savings, double credit);
void RunChoices(int *choicePtr);
void SelectAccount(char *accountPtr);
void AddMoney(double *moneyPtr);
void RemoveMoney(double *moneyPtr, char account);
int main()
{
	char tsth, slt; //tsth is for make another transaction(y or n), slt is select account(c, s, or r)
	double check = 650, saving = 800, credit = -700;
	int ch; //choice of 1 for deposit and 2 for withdrawl
	printf("Welcome to The Bank here are your account balances:\n");
	do {
		DisplayBalance(check, saving, credit);
		RunChoices(&ch);
		if (ch == 1)
		{
			SelectAccount(&slt);
			printf("~ making a Deposit\n");
			if (slt == 'c')
			{
				AddMoney(&check);
			}
			else if (slt == 's')
			{
				AddMoney(&saving);
			}
			else if (slt == 'r')
			{
				AddMoney(&credit);
			}
			else {
				printf("Not a valid selection\n");
			}
			printf("~ Here are your new account balances:\n");
			DisplayBalance(check, saving, credit);
		}
		else if (ch == 2)
		{
			SelectAccount(&slt);
			printf("~ To make a Withdrawal, here are your account balances:\n");
			DisplayBalance(check, saving, credit);
			if (slt == 'c')
			{
				RemoveMoney(&check, slt);
			}
			else if (slt == 's')
			{
				RemoveMoney(&saving, slt);
			}
			else if (slt == 'r')
			{
				RemoveMoney(&credit, slt);
			}
			else {
				printf("Not a valid selection\n");
			}
			printf("~ Here are your new account balances:\n");
			DisplayBalance(check, saving, credit);
		}
		else {
			printf("Not a valid option\n");
		}
		MakeTransaction(&tsth);
	} while (tsth == 'y');
	if (tsth == 'n')
	{
		printf("Thank you for using The Bank :)\n");
		scanf(" %c", &tsth); //prevent app close before say goodbye
	}
	return 0;
}
//Asks if they want another transaction 
//sets the value of againPtr to (y or n)
void MakeTransaction(char *againPtr)
{
	char th;
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("*** Would you like to make another transaction (y or n)?\n");
	scanf(" %c", &th);
	*againPtr = tolower(th);
	printf("You entered %c\n", th);
}
//Displays the user’s current account balance for all three accounts
void DisplayBalance(double checking, double savings, double credit)
{
	printf("\nChecking %.2f\n", checking);
	printf("Saving %.2f\n", savings);
	printf("Credit %.2f\n", credit);
}
// Displays the list of integer options available 
//prompts for the user’s choice and sets the value of the choicePtr
void RunChoices(int *choicePtr)
{
	printf("------------------\n");
	printf("Select an option:\n(1) for DEPOSIT\n(2) for WITHDRAWAL\n*** to make a TRANSFER\nselect(2) for WITHDRAWAL and\nthen(1) for DEPOSIT\n");
	scanf("%d", choicePtr);
	printf("You entered %d\n", *choicePtr);
}
//Asks the user which type of account they would like to access and sets the 
//value of the the character accountPtr
void SelectAccount(char *accountPtr)
{
	char sact;
	printf("~~~~~~~~~~~~~~~~~~~~\n");
	printf("Select the account:\n(C) for CHECKING\n(S) for SAVINGS\n(R) for CREDIT\n");
	scanf(" %c", &sact);
	*accountPtr = tolower(sact);
	printf("You entered %c\n", sact);
}
//Prompts the user for the amount to deposit 
//and adds that value to the amount in the bank account
void AddMoney(double *moneyPtr)
{
	double money;
	printf("Enter the amount you want to deposit\n");
	scanf("%lf", &money);
	*moneyPtr += money;
}
//Prompts the user for the amount of the withdrawal, determines if there are 
//sufficient funds and updates the selected account if funds are dispensed
void RemoveMoney(double *moneyPtr, char account)
{
	double money;
	printf("Enter the amount you want to withdrawal\n");
	scanf("%lf", &money);
	if (account != 'r' && money > *moneyPtr)
	{
		printf("Over the limit\n");
	}
	else if (account == 'r' && money - *moneyPtr > LIMIT)
	{
		printf("Over the limit\n");
	}
	else
	{
		*moneyPtr -= money;
	}

}
