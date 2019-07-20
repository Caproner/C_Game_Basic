#include "global.h"
#include "view.h"
#include "plane.h"
#include "bullet.h"
#include "enemy.h"

View view;
Plane plane;
BulletList bulletList;
int score;
Enemy enemy;
bool pauseFlag;

void pause()
{
	pauseFlag = true;
	view.gotoxy(HEIGHT + 3, 0);
	printf("Pause. Press any key to restart.");
}

void restart()
{
	pauseFlag = false;
	view.gotoxy(HEIGHT + 3, 0);
	printf("                                     ");
}

void getScore()
{
	score++;
	view.gotoxy(HEIGHT + 2, 7);
	printf("%d", score);
}

void initBorder(int h, int w)
{
	view.Clear();
	view.Set(0, 0, '+');
	for(int i = 1; i <= w; i++)
	{
		view.Set(0, i, '-');
	}
	view.Set(0, w + 1, '+') ;
	for(int i = 1; i <= h; i++)
	{
		view.Set(i, 0, '|');
		view.Set(i, w + 1, '|');
	}
	view.Set(h + 1, 0, '+');
	for(int i = 1; i <= w; i++)
	{
		view.Set(h + 1, i, '-');
	}
	view.Set(h + 1, w + 1, '+') ;
	view.gotoxy(h + 2, 0);
	printf("Score: %d", score);
}

void startup()
{
	srand(time(NULL));
	score = 0;
	initBorder(HEIGHT, WIDTH);
	plane.Init(20, 20, 1, WIDTH, 1, HEIGHT, view);
	bulletList.Init(1);
	enemy.Init(rand() % WIDTH + 1, HEIGHT, view);
}

void updateWithoutInput()
{
	if(!pauseFlag)
	{
		bulletList.Move(view);
		if(plane.CheckCrushBullet(bulletList, view))
		{
			plane.Destroy(view);
		}
		if(bulletList.CheckCrush(enemy.GetX(), enemy.GetY(), view))
		{
			enemy.Revive(view, true);
			getScore();
		}
		enemy.Move(view);
		if(plane.CheckCrush(enemy.GetX(), enemy.GetY()))
		{
			plane.Destroy(view);
		}
		if(bulletList.CheckCrush(enemy.GetX(), enemy.GetY(), view))
		{
			enemy.Revive(view, true);
			getScore();
		}
	}
}

void updateWithInput()
{
	if(kbhit())
	{
		char input = getch();
		if(pauseFlag)
		{
			restart();
			return;
		}
		if(input == 'a')
		{
			plane.MoveLeft(view);
		}
		if(input == 'd')
		{
			plane.MoveRight(view);
		}
		if(input == 'w')
		{
			plane.MoveTop(view);
		}
		if(input == 's')
		{
			plane.MoveBottom(view);
		}
		if(input == ' ')
		{
			bulletList.AddBullet(plane.GetX() - 1, plane.GetY(), view);
		}
		if(input == 27)
		{
			pause();
		}
	}
}

int main()
{
	startup();
	while(true)
	{
		updateWithoutInput();
		updateWithInput();
	}
	return 0;
}
