//Rong Zheng, 3/27/2017, small program 5
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int usernum();
void prif(double scores);
void add(double num1, double *num2);
int main()
{
	FILE *inptr;
	FILE *outptr;
	int num, i;
	double num1[24]; 
	double score, scores[24]; //Declare an array of doubles of size 25
	num = usernum(); //Ask the user how many doubles to get from the file<= 25
	inptr = fopen("doubleInput.txt", "r");
	for (i = 0; i < num; i++)
	{
		fscanf(inptr, "%lf", &scores[i]); //Use a loop to read the doubles into the array from the input file (fscanf).
		score = scores[i];
		prif(score); //print the doubles in the array onto the screen in a row
	}
	printf("\nafter adding 2.64\n");
	outptr = fopen("doubleOutput.txt", "w");
	for (i = 0; i < num; i++)
	{
		add(scores[i], &num1[i]); //Use a loop to add 2.64 to each number in the array and print
		fprintf(outptr, "%f      ", num1[i]); //fprint the new values of the doubles in the array into the output file
	}
	fclose(outptr);
	fclose(inptr);
	scanf("%d", &num);//prevent program from closing before showing result
	return 0;
}
//ask user how many doubles
int usernum()
{
	int num;
	printf("how many doubles to get from the file(<=25)?\n");
	scanf("%d", &num);
	return num;
}
//print the scores onto screen in a row
void prif(double scores)
{
	printf("%f   ", scores);
}
//add the doubles with 2.64 and print
void add(double num1, double *num2)
{
	*num2 = num1 + 2.64;
	printf("%f   ", *num2);
}