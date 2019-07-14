#include <cstdio>
#include <cstdlib>

void PrintPlane(const int &x, const int &y)
{
	system("cls");
	for(int i = 0; i < x; i++)
		printf("\n");
	for(int j = 0; j < y; j++)
		printf(" ");
	printf("*\n");
}

void MovePlane(int &x, int &y)
{
	char input;
	scanf("%c", &input);
	if(input == 'w')x--;
	if(input == 's')x++;
	if(input == 'a')y--;
	if(input == 'd')y++;
}

int main()
{
	int x = 5;
	int y = 10;
	
	while(1)
	{
		PrintPlane(x, y);
		MovePlane(x, y);
	}
	
	return 0;
}
