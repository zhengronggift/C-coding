//Rong Zheng, program 4, 4/24/2017 
#define _CRT_SECURE_NO_WARNINGS 
#include <string.h> 
#include <stdio.h> 
#include <ctype.h>
#define SIZE 40
typedef struct {
	int id;
	char artist[SIZE];
	char songName[SIZE];
	int length;
	double cost;
	double price;
}song;
void FillsongPtr(song *songptr);
//hardcodes five entries
void HCFive(song arrayS[]);
//Greets the user
void greet();
//runs the menu and gets the user choice
char menu();
//prints the contents of the list onto the screen
void rlist(song anylist);
//searches the list by id and returns the index, if there is a match or returns -1    
//three arguments: list, number of items, id
int search(song list[], int count, int transid);
//displays the ids in the list, gets the id from the user and returns it
int displayid(song list[], int count);
//adds an item to the list
void add(int count, song ylist[]);
//prints a report to a file
/*declare the file pointer, connect to the file and close the file pointer all inside this function*/
void report(int count, song list[]);
//removes an item from the list   
//takes three arguments, the list, the number of items and the location
void rem(int count, int del, song list[]);
//updates the sale price   
//takes three arguments, the list, the number of items and the location
void update(int count, int up, song list[]);
int main(){
	song slist[SIZE];
	int count = 5;
	int f, k;
	int transid;
	char main;
	greet();
	HCFive(slist);
	do {
		main = menu();
		if (main == 'P')
		{
			for (f = 0; f<count; f++)
			{
				printf("\n\n---Item %d\n", f+1);
				rlist(slist[f]);
			}
		}
		else if (main == 'A')
		{
			add(count, slist);
			count++;
		}
		else if (main == 'C')
		{
			count = 0;
			printf("\nsong cleared\n");
		}
		else if (main == 'D')
		{
			printf("\nCalling to delete function\n");
			transid = displayid(slist, count);
			k = search(slist, count, transid);
			if (k != -1)
			{
				rlist(slist[k]);
				printf("\nThe song %s will be deleted\n", slist[k].songName);
				rem(count, k, slist);
				count--;
			}
		}
		else if (main == 'S')
		{
			printf("\nCalling to create a report\n");
			report(count, slist);
		}
		else if (main == 'U')
		{
			printf("Calling to update price function\n");
			transid = displayid(slist, count);
			k = search(slist, count, transid);
			if (k != -1)
			{
				update(count, k, slist);
				rlist(slist[k]);
			}
		}
		else
		{
			printf("\nInput not recognized\n");
		}
		if (count == 0)
		{
			printf("\n******************\nThe list is empty\n");
		}
	} while (main != 'Q');
	return 0;
}
void greet()
{
	printf("Welcome to the song inventory\n");
	printf("This program manages a list of songs\n");
	printf("Each song has a unique id\n");
	printf("Follow the prompts on the menu:\n");
}
char menu()
{
	char select;
	char low;
	printf("\n---------------\nSelect an option\n");
	printf("P....Print the inventory list onto the screen \nA....Add a new entry \nC....Clear all records \nS....Create a current report (save it to a file) \nD....Delete an item from the list (inventory) \nU....Update ONE OF THE FIELDS (not THE id) \nQ....Quit\n");
	scanf(" %c", &low);
	select = toupper(low);
	printf("You entered %c", select);
	return select;
}
void add(int count, song ylist[])
{
	int c;
	printf("\nCalling Add function\n");
	c = count++;
	FillsongPtr(&ylist[c]);
}
void report(int count, song list[])
{
	int i;
	FILE *rep;
	rep = fopen("report.txt","w");
	for (i = 0; i < count; i++) 
	{
		fprintf(rep, "\n\n---Item %d\n", i+1);
		fprintf(rep, "\n\The artist is:  %s\n", list[i].artist);
		fprintf(rep, "The id is:: %d\n", list[i].id);
		fprintf(rep, "The song title is:  %s\n", list[i].songName);
		fprintf(rep, "The length of the song (in seconds) is:  %d seconds\n", list[i].length);
		fprintf(rep, "The cost of the song is: $%.2f\n", list[i].cost);
		fprintf(rep, "The retail price of the song is: $%.2f\n", list[i].price);
	}
	fclose(rep);
}
int search(song list[], int count, int transid)
{
	int i, m=0;
	for (i = 0; i < count; i++)
	{
		if (transid == list[i].id)
		{
			return i;
			m++;
		}
	}
	if (m == 0)
	{
		printf("No Match Id found");
		return -1;
	}
}
void rlist(song anylist)
{
	printf("\n\The artist is:  %s\n", anylist.artist);
	printf("The id is: %d\n", anylist.id);
	printf("The song title is:  %s\n", anylist.songName); 
	printf("The length of the song (in seconds) is:  %d seconds\n", anylist.length); 
	printf("The cost of the song is: $%.2f\n", anylist.cost);
	printf("The retail price of the song is: $%.2f\n", anylist.price);
}
//Function Definitions // fills the data fields of a song instance //returns the filled song
//fills the data fields of a song instance //by reference using a pointer to a song
void FillsongPtr(song *songptr) {
	//prompt and get information
	printf("Getting the song from the FillsongPtr function\n");
	printf("\nEnter the artist of the song:  ");
	scanf("%s", &(*songptr).artist);
	printf("\nEnter id:  ");
	scanf("%d", &(*songptr).id);
	//prompt and get information
	printf("\nEnter the title of the song:  ");
	scanf("%s", &(*songptr).songName); //scanf("%s", songptr->songName);
									   //prompt and get information
	printf("\nEnter the length of the song(seconds):  ");
	scanf("%d", &(*songptr).length);
	printf("\nEnter the cost of the song: $  ");
	scanf("%lf", &(*songptr).cost);
	printf("\nEnter the retail price of the song: $  ");
	scanf("%lf", &(*songptr).price);
}
void HCFive(song arrayS[]) {
	strcpy(arrayS[0].artist, "Incubus");
	strcpy(arrayS[0].songName, "NiceToKnowYou");
	arrayS[0].id = 421;
	arrayS[0].length = 30;
	arrayS[0].cost = 2;
	arrayS[0].price = 5;
	strcpy(arrayS[1].artist, "DirtyHeads");
	strcpy(arrayS[1].songName, "CabinByTheSea");
	arrayS[1].id = 232;
	arrayS[1].length = 31;
	arrayS[1].cost = 12;
	arrayS[1].price = 15;
	strcpy(arrayS[2].artist, "MilkyChance");
	strcpy(arrayS[2].songName, "StolenDance");
	arrayS[2].id = 983;
	arrayS[2].length = 30;
	arrayS[2].cost = 22;
	arrayS[2].price = 25;
	strcpy(arrayS[3].artist, "GeorgeEzra");
	strcpy(arrayS[3].songName, "Budapest");
	arrayS[3].id = 324;
	arrayS[3].length = 33;
	arrayS[3].cost = 23;
	arrayS[3].price = 35;
	strcpy(arrayS[4].artist, "PearlJam");
	strcpy(arrayS[4].songName, "YellowLedbetter");
	arrayS[4].id = 125;
	arrayS[4].length = 34;
	arrayS[4].cost = 24;
	arrayS[4].price = 54;
}
int displayid(song list[], int count)
{
	int i;
	printf("\nHere are the ID numbers and the song titles\n");
	for (i = 0; i < count; i++) {
		printf("\n%d  %s ", list[i].id, list[i].songName);
		printf("\n");
	}
	printf("\nenter id number\n");
	scanf("%d", &i);
	return i;
}
void rem(int count, int del, song list[])
{
	int i;
	for (i = del; i < count; i++)
	{
		list[i] = list[i + 1];
	}
}
void update(int count, int up, song list[])
{
	printf("$%.2f is current price for %s\n", list[up].price, list[up].songName);
	printf("Enter new price\n");
	scanf("%lf", &list[up].price);
	printf("The price has been updated\n");
}
