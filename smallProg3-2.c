//Rong Zheng, 2/7/2017, small program 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
int GetInt(void);
double GetDouble(void);
double FunctionMultiply(int arg1, double arg2);
char GetLetter(void);
int FunctionCharacter(char arg1);
int main(){
	int arg1, ret;
	double arg2, res;
	char let;
	arg1 = GetInt();
	arg2 = GetDouble();
	res = FunctionMultiply(arg1, arg2);
	printf("The product of the interger and double is %f\n", res);
	let = GetLetter();
	ret = FunctionCharacter(let);
	printf("The entered letter returns %d (0 for alphabet a-m, 1 for alphabet n-z)\n", ret);
	scanf("%d", &arg1); //stop program from closing before showing the answer
return 0;
}
// gets an integer from the user and returns it int GetInt(void)
int GetInt(void)
{
	int num;
	printf("Please enter an interger and press Enter\n");
	scanf("%d", &num);
	return num;
}
// gets a double from the user and returns it int GetDouble(void)
double GetDouble(void)
{
	double num2;
	printf("Please enter a double and press Enter\n");
	scanf("%lf", &num2);
	return num2;
}
// gets a letter from the user and returns it char GetLetter(void)
char GetLetter(void)
{
	char let;
	printf("Please enter a letter and press Enter\n");
	scanf(" %c", &let);
	return let;
}
// takes two arguments, an integer and a double 
//multiplies the value of the double argument by the value of the integer argument
//and returns the product double FunctionMultiply(int arg1, double arg2)
double FunctionMultiply(int arg1, double arg2)
{
	double product;
	product = arg1 * arg2;
	return product;
}
// takes one character argument and returns an integer
//change the letter to lowercase (use ctype.h)
//return a 0 if the letter is in the first half of the alphabet (a-m)
//return a 1 if the letter is in the second half of the alphabet (n-z) int FunctionCharacter(char arg1);
int FunctionCharacter(char arg1)
{
	char let;
	let = tolower(arg1); 
	if (let <= 'm'){
		return 0;
	}
	else {
		return 1;
	}
}