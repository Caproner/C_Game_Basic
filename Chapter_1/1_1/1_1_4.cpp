#include <cstdio>
#include <cstdlib>

void PrintBall(const int &x, const int &y)
{
	system("cls");
	for(int i = 0; i < x; i++)
		printf("\n");
	for(int j = 0; j < y; j++)
		printf(" ");
	printf("o\n");
}

int main()
{
	int x = 0, y = 5;
	int velocity_x = 1, velocity_y = 1;
	int left = 0;
	int right = 20;
	int top = 0;
	int bottom = 10;
	
	while(1)
	{
		x += velocity_x;
		y += velocity_y;
		
		PrintBall(x, y);
		
		if(x == top || x == bottom)
			velocity_x = -velocity_x;
		if(y == left || y == right)
			velocity_y = - velocity_y;
	}
	
	return 0;
}
