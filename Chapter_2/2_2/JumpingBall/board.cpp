#include "board.h"

void Board::Init(View &view)
{
	x = INIT_BOARD_X;
	y_left = INIT_BOARD_Y_LEFT;
	y_right = INIT_BOARD_Y_RIGHT;
	for(int i = y_left; i <= y_right; i++)
	{
		view.Set(x, i, '*');
	}
}

void Board::Move(int v_x, int v_y, View &view)
{
	if(x + v_x < BOARD_X_MIN)return;
	if(x + v_x > BOARD_X_MAX)return;
	if(y_left + v_y < 1)return;
	if(y_right + v_y > WIDTH)return;
	for(int i = y_left; i <= y_right; i++)
	{
		if(view.Get(x + v_x, i + v_y) == '*')
		{
			continue;
		}
		if(view.Get(x + v_x, i + v_y) != ' ')
		{
			return;
		}
	}
	for(int i = y_left; i <= y_right; i++)
	{
		view.Delete(x, i);
	}
	x += v_x;
	y_left += v_y;
	y_right += v_y;
	for(int i = y_left; i <= y_right; i++)
	{
		view.Set(x, i, '*');
	}
}
