#include <cstdio>

void PrintBall(const int &x, const int &y)
{
	for(int i = 0; i < x; i++)
		printf("\n");
	for(int j = 0; j < y; j++)
		printf(" ");
	printf("o\n");
}

int main()
{
	int x = 16;
	int y = 2;
	
	PrintBall(x, y);
	
	return 0;
}
