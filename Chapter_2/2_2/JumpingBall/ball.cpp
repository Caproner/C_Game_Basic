#include "ball.h"

void Ball::Init(View &view)
{
	x = INIT_BALL_X;
	y = INIT_BALL_Y;
	v_x = INIT_BALL_VX;
	v_y = INIT_BALL_VY;
	lastMoveTime = clock();
	view.Set(x, y, 'O');
}

void Ball::Move(View &view)
{
	double waitTime = (double)(clock() - lastMoveTime) / CLOCKS_PER_SEC;
	if(waitTime < (1.0 / BALL_SPEED))
	{
		return;
	}
	lastMoveTime = clock();
	if(view.Get(x + v_x, y + v_y) != ' ')
	{
		return;
	}
	view.Delete(x, y);
	x += v_x;
	y += v_y;
	view.Set(x, y, 'O');
}

bool Ball::Collide(View &view, Block &block, bool &isCollideBlock)
{
	isCollideBlock = false;
	char x_elem = view.Get(x + v_x, y);
	char y_elem = view.Get(x, y + v_y);
	char xy_elem = view.Get(x + v_x, y + v_y);
	if(((xy_elem != ' ') && (x_elem == ' ') && (y_elem == ' ')))
	{
		if(xy_elem == 'B')
		{
			isCollideBlock = true;
			block.Erase(x + v_x, y + v_y, view);
		}
		v_x = - v_x;
		v_y = - v_y;
	}
	else if(y_elem != ' ')
	{
		if(y_elem == 'B')
		{
			isCollideBlock = true;
			block.Erase(x, y + v_y, view);
		}
		v_y = - v_y;
	}
	else if(x_elem != ' ')
	{
		if(x_elem == 'B')
		{
			isCollideBlock = true;
			block.Erase(x + v_x, y, view);
		}
		v_x = - v_x;
	}
	else
	{
		return false;
	}
	return true;
}

bool Ball::CheckFall()
{
	return x == HEIGHT + 1;
}
