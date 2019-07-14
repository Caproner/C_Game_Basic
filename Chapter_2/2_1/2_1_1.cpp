#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <algorithm>

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
	
	void Move(const int &right, const int &bottom)
	{
		if(kbhit())
		{
			char input = getch();
			if(input == 'w')x--;
			if(input == 's')x++;
			if(input == 'a')y--;
			if(input == 'd')y++;
			if(input == ' ')isFire = true;
			x = std::max(x, 0);
			x = std::min(x, bottom);
			y = std::max(y, 0);
			y = std::min(y, right);
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
	
	void Revive(const Plane &p, const int &right)
	{
		while(y == p.y)
		{
			y = rand() % (right + 1);
		}
		vec = rand() % 3 - 1;
		lastMoveTime = clock();
	}
	
	void Move(const int &right)
	{
		double waitTime = (double)(clock() - lastMoveTime) / CLOCKS_PER_SEC;
		if(waitTime >= 1)
		{
			y += vec;
			if(y == right || y == 0)
			{
				vec = -vec;
			}
			lastMoveTime = clock();
		}
	}
	
	void Check(Plane &p, const int &right)
	{
		if(!p.isFire)return;
		if(y == p.y)
		{
			p.isFire = false;
			p.score++;
			this->Revive(p, right);
		}
	}
};

// 显示类 
struct Screen
{
	int right, bottom;
	
	Screen(int _right = 30, int _bottom = 20)
	{
		right = _right;
		bottom = _bottom;
	}
	
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

Plane plane;
Target target;
Screen screen;

void startup()
{
	srand(time(NULL));
}

void show()
{
	screen.Print(plane, target);
}

void updateWithoutInput()
{
	target.Move(screen.right);
	target.Check(plane, screen.right);
}

void updateWithInput()
{
	plane.Move(screen.right, screen.bottom);
}

int main()
{
	startup();
	while(true)
	{
		show();
		updateWithoutInput();
		updateWithInput();
	}
	
	return 0;
}
