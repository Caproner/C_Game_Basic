#include <cstdio>
#include <cstdlib>
#include <windows.h>

void PrintBall(	const int &x,
				const int &y,
				const int &left,
				const int &right,
				const int &top,
				const int &bottom)
{
	system("cls");
	for(int i = 0; i <= bottom + 1; i++)
	{
		for(int j = 0; j <= right + 1; j++)
		{
			if(i == x && j == y)
				printf("£ï");
			else if(i == top - 1)
			{
				if(j == left - 1)
					printf("©°");
				else if(j == right + 1)
					printf("©´");
				else
					printf("©¤");
			}
			else if(i == bottom + 1)
			{
				if(j == left - 1)
					printf("©¸");
				else if(j == right + 1)
					printf("©¼");
				else
					printf("©¤");
			}
			else if(j == left - 1 || j == right + 1)
				printf("©¦");
			else
				printf("  ");
			
		}
		printf("\n");
	}
	Sleep(50);
}

int main()
{
	int x = 5, y = 5;
	int velocity_x = 1, velocity_y = 1;
	int left = 1;
	int right = 20;
	int top = 1;
	int bottom = 10;
	
	while(1)
	{
		x += velocity_x;
		y += velocity_y;
		
		PrintBall(x, y, left, right, top, bottom);
		
		if(x == top || x == bottom)
			velocity_x = -velocity_x;
		if(y == left || y == right)
			velocity_y = - velocity_y;
	}
	
	return 0;
}
