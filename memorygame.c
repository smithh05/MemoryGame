#include <stdlib.h> 
#include <time.h>
#include <stdio.h>

#define HEIGHT 8
#define WIDTH 10

typedef struct data 
	{ 
		char card; 
		int show; 
	} Data;
	
int gameCounter = 0;
int boardSize = HEIGHT * WIDTH;

void GenerateField(Data cards[HEIGHT][WIDTH]); 
void CreateField(Data cards[HEIGHT][WIDTH]); 
void HideBoard(Data cards[HEIGHT][WIDTH]);
void ShowBoard(Data cards[HEIGHT][WIDTH]);
void Input(Data cards[HEIGHT][WIDTH]);
void Print(Data cards[HEIGHT][WIDTH]);
void GameOver();

int main()
{
	Data cards[HEIGHT][WIDTH]; 
	srand(time(NULL));
	CreateField(cards); 
	GenerateField(cards); 
	HideBoard(cards);
	Print(cards);
	while(gameCounter != boardSize)
	{
		Input(cards);
		Print(cards);
	}
	GameOver();
	ShowBoard(cards);
	return 0; 
}

void CreateField(Data cards[HEIGHT][WIDTH])
{
	int i, j = 0;
	for(i = 0; i < HEIGHT; i++)
		{ 
			printf(" \n"); 
				for(j = 0; j < WIDTH; j++)
				{ 
					cards[i][j].card = '0';
					printf(" %c",cards[i][j].card); 
				} 
		} 
		printf("\n Board created... \n"); 
}

void GenerateField(Data cards[HEIGHT][WIDTH]) 
{

	int counter = 0; 
	char numbers[] = {'1','1','1','1','2','2','2','2','3','3','3','3','4','4','4','4','5','5','5','5','6','6','6','6',
		              '7','7','7','7','8','8','8','8','9','9','9','9','A','A','A','A','B','B','B','B','C','C','C','C',
		              'D','D','D','D','E','E','E','E','F','F','F','F','G','G','G','G','H','H','H','H','I','I','I','I',
		              'J','J','J','J','K','K','K','K'};
	int random1, random2 = 0;  
	while(counter < boardSize)
	{ 
		random1 = rand() % HEIGHT; 
		random2 = rand() % WIDTH; 
		if(cards[random1][random2].card == '0')
		{ 
			cards[random1][random2].card = numbers[counter]; 
			counter++; 
		} 
	} 
	return; 
}

void HideBoard(Data cards[HEIGHT][WIDTH])
{
	int i, j = 0;
	for(i = 0; i < HEIGHT; i++)
	{ 
		for(j = 0; j < WIDTH; j++)
		{ 
			cards[i][j].show = 0;
		} 
	} 
}

void ShowBoard(Data cards[HEIGHT][WIDTH])
{
	int i, j = 0;
	for(i = 0; i < HEIGHT; i++)
	{ 
		for(j = 0; j < WIDTH; j++)
		{ 
			cards[i][j].show = 1;
		} 
	} 
}

void Print(Data cards[HEIGHT][WIDTH])
{ 
	int i, j = 0;
	for(i = 0; i < HEIGHT; i++)
	{ 
		printf(" \n"); 
		for(j = 0; j < WIDTH; j++)
		{ 
			if(cards[i][j].show == 0)
			{
				printf(" 0");
			}
			else
			{
				printf(" %c",cards[i][j].card);
			} 
		} 
	} 
	printf(" \n"); 
}

void Input(Data cards[HEIGHT][WIDTH])
{
	int row1, column1, row2, column2 = 0;
	printf("Please enter the row of the first card: ");
	scanf("%d",&row1);
	printf("Please enter the column of the first card: ");
	scanf("%d",&column1);
	cards[row1][column1].show = 1;
	Print(cards);
	printf("Please enter the row of the second card: ");
	scanf("%d",&row2);
	printf("Please enter the column of the second card: ");
	scanf("%d",&column2);
	cards[row2][column2].show = 1;
	Print(cards);
	if(cards[row1][column1].card == cards[row2][column2].card)
	{
		printf("You've found a match!");
		gameCounter += 2;
	}
	else 
	{
		cards[row1][column1].show = 0;
		cards[row2][column2].show = 0;
		printf("You didn't find a match. Try again!");
	}
}

void GameOver()
{
	printf("Game Over! Thanks for playing!");
}
