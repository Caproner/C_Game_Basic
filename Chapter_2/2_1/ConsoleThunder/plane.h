#include "global.h"
#include "view.h"
#include "bullet.h"

#ifndef PLANE
#define PLANE
class Plane
{
	int x, y;
	int b_left, b_right, b_top, b_bottom;
	
public:
	
	void Init(int _x, int _y, int _left, int _right, int _top, int _bottom, View &view);
	int GetX();
	int GetY();
	void MoveLeft(View &view);
	void MoveRight(View &view);
	void MoveTop(View &view);
	void MoveBottom(View &view);
	void Shot(View &view);
	void Destroy(View &view);
	bool CheckCrushBullet(BulletList &bulletList, View &view);
	bool CheckCrush(int _x, int _y);
};
#endif
