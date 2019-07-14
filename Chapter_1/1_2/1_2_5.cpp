#include <cstdio>
#include <cstdlib>
#include <conio.h>

void PrintPlane(const int &x, 
				const int &y, 
				const bool &isFire,
				const int &ny,
				const bool &isKill)
{
	system("cls");
	if(!isKill)
	{
		for(int i = 0; i < ny; i++)
			printf(" ");
		printf("  +");
	}
	printf("\n");
	for(int i = 0; i < x; i++)
	{
		if(isFire)
		{
			for(int j = 0; j < y; j++)
				printf(" ");
			printf("  |");
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

void KillCheck(	const int &y,
				const int &ny,
				bool &isFire,
				bool &isKill)
{
	if(isKill || (!isFire))return;
	if(y == ny)
	{
		isKill = true;
		isFire = false;
	}
}

int main()
{
	int x = 5;
	int y = 10;
	bool isFire = false;
	
	int ny = 5;
	bool isKill = false;
	
	while(1)
	{
		PrintPlane(x, y, isFire, ny, isKill);
		MovePlane(x, y, isFire);
		KillCheck(y, ny, isFire, isKill);
	}
	
	return 0;
}
