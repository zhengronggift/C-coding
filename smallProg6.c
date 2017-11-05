//Rong Zheng, small program 6, 4/15/2017
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#define SIZE 20
typedef struct {
	char artist[SIZE];
	char songName[SIZE];
	int length;
	double cost;
}song;
//Function Prototypes
// fills the data fields of a song instance
//returns the filled song 
song Fillsong();
//fills the data fields of a song instance
//by reference using a pointer to a song
void FillsongPtr(song *songptr);
//fills an array of songs
void FillsongArray(song arrayS[], int *size);
//displays one song
void Displaysong(song anysong);
int main()
{
	//Declare variables
	song mysong, mysong1, mysong2;
	song manysongs[SIZE];
	int sSize;
	int i;

	//Fill structures with a function
	mysong = Fillsong();
	mysong1 = Fillsong();

	//print using display function
	printf("\n---------Display mysong\n");
	Displaysong(mysong);
	printf("\n---------Display mysong1\n");
	Displaysong(mysong1);

	//Fill structure using pointers and dispay it
	FillsongPtr(&mysong2);
	printf("\n---------Display mysong2\n");
	Displaysong(mysong2);

	//Fill the array with the function
	printf("\n---------Fill array manysongs\n");
	FillsongArray(manysongs, &sSize);

	//display an array of songs
	printf("\n---------Display array manysongs\n");
	for (i = 0; i<sSize; i++)
	{
		Displaysong(manysongs[i]);
	}

	return 0;
}

//Function Definitions
// fills the data fields of a song instance
//returns the filled song 
song Fillsong()
{
	//Declare local variables
	song tempS;
	//prompt and get information
	printf("\nplease enter the artist of your song:  ");
	scanf("%s", &tempS.artist);
	//print to check
	printf("artist:  %s\n", tempS.artist);

	//prompt and get information
	printf("\nplease enter the name of your song:  ");
	scanf("%s", &tempS.songName);
	//print to check
	printf("song name:  %s\n", tempS.songName);

	//prompt and get information
	printf("\nplease enter the length of your song(seconds):  ");
	scanf("%d", &tempS.length);
	printf("length:  %d seconds\n", tempS.length);

	printf("\nplease enter the cost of your song: $  ");
	scanf("%lf", &tempS.cost);
	printf("cost: $ %.2f \n", tempS.cost);
	return tempS;
}

//displays one song
void Displaysong(song anysong)
{
	printf("\n\nartist:  %s\n", anysong.artist);
	printf("song name:  %s\n", anysong.songName);
	printf("length:  %d seconds\n", anysong.length);
	printf("cost: $%.2f\n", anysong.cost);
}

//fills the data fields of a song instance
//by reference using a pointer to a song
void FillsongPtr(song *songptr)
{
	//prompt and get information
	printf("\nplease enter the artist of your song:  ");
	scanf("%s", &(*songptr).artist);

	//prompt and get information
	printf("\nplease enter the name of your song:  ");
	scanf("%s", &(*songptr).songName); //scanf("%s", songptr->songName);

	//prompt and get information
	printf("\nplease enter the length of your song(seconds):  ");
	scanf("%d", &(*songptr).length);
	printf("\nplease enter the cost of your song: $  ");
	scanf("%lf", &(*songptr).cost);
}

//fills an array of songs
void FillsongArray(song arrayS[], int *size)
{
	int i;
	//prompt the user
	printf("\nenter the number of songs:  ");
	scanf("%d", size);

	//print to check
	printf("size:  %d\n", *size);

	for (i = 0; i < *size; i++)
	{
		printf("enter artist:  ");
		scanf("%s", &arrayS[i].artist);

		printf("enter song name:  ");
		scanf("%s", &arrayS[i].songName);

		printf("enter length(seconds):  ");
		scanf("%d", &arrayS[i].length);

		printf("enter cost: $ ");
		scanf("%lf", &arrayS[i].cost);
	}
}