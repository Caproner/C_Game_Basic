#include "global.h"
#include "view.h"
#include "board.h"
#include "ball.h"
#include "block.h"

View view;
Board board;
Ball ball;
Block block;
int score;
int collideTimes;
bool getScoreFlag;

void gameOver()
{
	for(int i = 0; i <= WIDTH + 1; i++)
	{
		view.Set(HEIGHT / 2 - 2, i, '-');
		view.Delete(HEIGHT / 2 - 1, i);
		view.Delete(HEIGHT / 2, i);
		view.Delete(HEIGHT / 2 + 1, i);
		view.Set(HEIGHT / 2 + 2, i, '-');
	}
	view.Flush();
	view.gotoxy(HEIGHT / 2, WIDTH / 2 - 4);
	printf("GAME  OVER");
	Sleep(3000);
	char input = getch();
	view.gotoxy(HEIGHT + 4, 0);
	exit(0);
}

void getScore()
{
	score++;
	view.gotoxy(HEIGHT + 2, 7);
	printf("%d", score);
}

void getCollideTimes()
{
	collideTimes++;
	view.gotoxy(HEIGHT + 3, 15);
	printf("%d", collideTimes);
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
	view.Set(h + 1, w + 1, '+') ;
	view.gotoxy(h + 2, 0);
	printf("Score: %d", score);
	view.gotoxy(h + 3, 0);
	printf("Collide Times: %d", collideTimes);
}

void startup()
{
	srand(time(NULL));
	score = 0;
	collideTimes = 0;
	initBorder(HEIGHT, WIDTH);
	board.Init(view);
	ball.Init(view);
	block.Init(view);
}

void show()
{
	view.Flush();
}

void ballCollide()
{
	if(ball.Collide(view, block, getScoreFlag))
	{
		getCollideTimes();
		if(getScoreFlag)
		{
			getScore();
		}
	}
}

void updateWithoutInput()
{
	ballCollide();
	ball.Move(view);
	if(ball.CheckFall())gameOver();
	ballCollide();
}

void updateWithInput()
{
	if(kbhit())
	{
		char input = getch();
		if(input == 'w')
		{
			board.Move(-1, 0, view);
		}
		if(input == 's')
		{
			board.Move(1, 0, view);
		}
		if(input == 'a')
		{
			board.Move(0, -1, view);
		}
		if(input == 'd')
		{
			board.Move(0, 1, view);
		}
	}
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
