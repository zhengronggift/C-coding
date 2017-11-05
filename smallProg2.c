//Rong Zheng, 1/24/2017, small program 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
int main()
{
	int num, mnum;
	char let, ulet, llet;
	printf("Hello, my name is Rong Zheng\n"); //1. Print “Hello my name is (add your name here)” onto the screen.
	printf("Please type in a number and press Enter => "); //2. Ask the user for a number.
	scanf("%d", &num); //3. Scan the number from the user.
	mnum = num * 3; //	4. Multiply the number by 3
	printf("The number entered was %d, multiply by 3 = %d \n", num, mnum); //	5. Print the number and the product back onto the screen.
	printf("Please type in a letter and press Enter => "); //	6. Ask the user for a letter.
	scanf(" %c", &let); //	7. Scan the letter from the user.
	ulet = toupper(let); //	8. Make an uppercase version of the letter(use the library ctype.h)
	llet = tolower(let); //	9. Make a lowercase version of the letter(use the library ctype.h)
	printf("Uppercase=> %c Lowercase=> %c \n", ulet, llet); //	10. Print both the uppercase and lowercase letters back onto the screen.
	return 0;
}