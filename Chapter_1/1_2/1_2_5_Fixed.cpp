#include <cstdio>
#include <cstdlib>
#include <conio.h>

// 飞机类 
struct Plane
{
	int x, y;
	bool isFire;
	
	Plane(int _x = 10, int _y = 10, bool _isFire = false)
	{
		x = _x;
		y = _y;
		isFire = _isFire;
	}
	
	void Move()
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
};

// 靶类 
struct Target
{
	int y;
	bool isKill;
	
	Target(int _y = 5, bool _isKill = false)
	{
		y = _y;
		isKill = _isKill;
	}
	
	void Check(Plane &p)
	{
		if(isKill || (!p.isFire))return;
		if(y == p.y)
		{
			isKill = true;
			p.isFire = false;
		}
	}
};

// 显示类 
struct Screen
{
	void Print(const Plane &p, const Target &t)
	{
		system("cls");
		if(!t.isKill)
		{
			for(int i = 0; i < t.y; i++)
				printf(" ");
			printf("  +");
		}
		printf("\n");
		for(int i = 0; i < p.x; i++)
		{
			if(p.isFire)
			{
				for(int j = 0; j < p.y; j++)
					printf(" ");
				printf("  |");
			}
			printf("\n");
		}
		for(int j = 0; j < p.y; j++)
			printf(" ");
		printf("  *\n");
		for(int j = 0; j < p.y; j++)
			printf(" ");
		printf("*****\n");
		for(int j = 0; j < p.y; j++)
			printf(" ");
		printf(" * *\n");
	} 
};

int main()
{
	Plane plane;
	Target target;
	Screen screen;
	
	while(true)
	{
		screen.Print(plane, target);
		plane.Move();
		target.Check(plane);
	}
	
	return 0;
}
