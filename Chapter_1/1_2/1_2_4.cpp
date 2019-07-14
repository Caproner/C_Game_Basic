#include <cstdio>
#include <cstdlib>
#include <conio.h>

void PrintPlane(const int &x, const int &y, const bool &isFire)
{
	system("cls");
	for(int i = 0; i < x; i++)
	{
		if(isFire)
		{
			for(int j = 0; j < y + 2; j++)
				printf(" ");
			printf("|");
		}
		printf("\n");
	}
	for(int j = 0; j < y; j++)
		printf(" ");
	printf("  *\n");
	for(int j = 0; j < y; j++)
		printf(" ");
	printf("*****\n");
	for(int j = 0; j < y; j++)
		printf(" ");
	printf(" * *\n");
}

void MovePlane(int &x, int &y, bool &isFire)
{
	if(kbhit())
	{
		char input = getch();
		if(input == 'w')x--;
		if(input == 's')x++;
		if(input == 'a')y--;
		if(input == 'd')y++;
		if(input == ' ')isFire = true;
	}
}

int main()
{
	int x = 5;
	int y = 10;
	bool isFire = false;
	
	while(1)
	{
		PrintPlane(x, y, isFire);
		MovePlane(x, y, isFire);
	}
	
	return 0;
}
