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
	int x = 5, y = 10;
	int height = 20;
	int velocity = 1;
	
	// ÉÁµÄÀÏ×ÓÑÛÏ¹= = 
	while(1)
	{
		x += velocity;
		
		PrintBall(x, y);
		
		if(x == height || x == 0)
			velocity = -velocity;
	}
	
	return 0;
}
