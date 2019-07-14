#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <ctime>

// 飞机类 
struct Plane
{
	int x, y;
	bool isFire;
	int score;
	
	Plane(int _x = 10, int _y = 10, bool _isFire = false)
	{
		x = _x;
		y = _y;
		isFire = _isFire;
		score = 0;
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
	int y, vec;
	clock_t lastMoveTime;
	
	Target(int _y = 5)
	{
		y = _y;
		vec = 1;
		lastMoveTime = clock();
	}
	
	void Revive(const Plane &p)
	{
		while(y == p.y)
		{
			y = rand() % 31;
		}
		vec = rand() % 3 - 1;
		lastMoveTime = clock();
	}
	
	void Move()
	{
		double waitTime = (double)(clock() - lastMoveTime) / CLOCKS_PER_SEC;
		if(waitTime >= 1)
		{
			y += vec;
			if(y == 30 || y == 0)
			{
				vec = -vec;
			}
			lastMoveTime = clock();
		}
	}
	
	void Check(Plane &p)
	{
		if(!p.isFire)return;
		if(y == p.y)
		{
			p.isFire = false;
			p.score++;
			this->Revive(p);
		}
	}
};

// 显示类 
struct Screen
{
	void Print(const Plane &p, const Target &t)
	{
		system("cls");
		printf("Score : %d\n\n", p.score);
		for(int i = 0; i < t.y; i++)
			printf(" ");
		printf("  +");
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
	srand(time(NULL));
	Plane plane;
	Target target;
	Screen screen;
	
	while(true)
	{
		screen.Print(plane, target);
		plane.Move();
		target.Move();
		target.Check(plane);
	}
	
	return 0;
}
