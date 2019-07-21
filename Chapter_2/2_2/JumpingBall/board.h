#include "global.h"
#include "view.h"

#ifndef BOARD
#define BOARD
class Board
{
	int x, y_left, y_right;
public:
	void Init(View &view);
	void Move(int v_x, int v_y, View &view);
};
#endif
