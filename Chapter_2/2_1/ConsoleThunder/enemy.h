#include "global.h"
#include "view.h"

#ifndef ENEMY
#define ENEMY
class Enemy
{
	int x, y;
	int b_bottom;
	double speed;
	clock_t lastMoveTime;
public:
	void Init(int _y, int _bottom, View &view);
	void Move(View &view);
	void Revive(View &view, bool isShooted);
	int GetX();
	int GetY();
};
#endif
