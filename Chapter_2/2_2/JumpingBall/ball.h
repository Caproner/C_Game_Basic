#include "global.h"
#include "view.h"
#include "block.h"

#ifndef BALL
#define BALL
class Ball
{
	int x, y;
	int v_x, v_y;
	clock_t lastMoveTime;
public:
	void Init(View &view);
	void Move(View &view);
	bool Collide(View &view, Block &block, bool &isCollideBlock);
	bool CheckFall();
};
#endif
