#include <cstdio>
#include <cstdlib>

int main()
{
	int x = 5;
	int y = 10;
	char input;
	
	while(1)
	{
		system("cls");
		for(int i = 0; i < x; i++)
			printf("\n");
		for(int j = 0; j < y; j++)
			printf(" ");
		printf("*\n");
		
		scanf("%c", &input);
		if(input == 'w')x--;
		if(input == 's')x++;
		if(input == 'a')y--;
		if(input == 'd')y++;
	}
	
	return 0;
}
