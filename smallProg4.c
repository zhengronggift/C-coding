//Rong Zheng , 3/14/2017, small program 4
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
void CalculateBoth(int num1, int num2, int*prodPtr, int *remPtr);
int main()
{
	int i, num, num2, cal1, cal2, prod, rem;
	printf("enter 1-9\n");
	scanf("%d", &num);
	num2 = num;
	for (i = 1; i <= num; i++)
	{
		printf("FAU Owls - Hoot Hoot\n");
	}
	do
	{
		printf("Programming is awesome\n");
		num--;
	} while (num != 0);
	while (num2 != 0)
	{
		printf("Florida beaches are beautiful\n");
		num2--;
	}
	printf("enter a value\n");
	scanf("%d", &cal1);
	printf("enter another value\n");
	scanf("%d", &cal2);
	CalculateBoth(cal1, cal2, &prod, &rem);
	printf("the value of product and remainder inside the main function are %d, %d\n", prod, rem);
}
//takes two integer arguments and two integer pointer arguments
//1. calculate the product and stores the result in prodPtr
//2. calculate the remainder of num1 % num2 and store the result in remPtr
//if num2 is 0 do not calculate the remainder and the value at remPtr will be 0
void CalculateBoth(int num1, int num2, int*prodPtr, int *remPtr)
{
	*prodPtr = num1 * num2;
	if (num2 != 0)
	{
		*remPtr = num1%num2;
	}
	else
	{
		*remPtr = 0;
	}
	printf("the value of product and remainder inside the CalculateBoth function are %d, %d\n", *prodPtr, *remPtr);

}