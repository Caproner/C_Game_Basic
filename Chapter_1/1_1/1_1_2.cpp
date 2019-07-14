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
	int y = 10;
	
	for(int x = 1; x < 10; x++)
		PrintBall(x, y);
	
	return 0;
}
