#include "global.h"
#include "view.h"

#ifndef BULLETLIST
#define BULLETLIST
class BulletList
{
	std::pair<int, int> b_list[10005];
	int len;
	int b_top;
	clock_t lastMoveTime;
	
public:
	
	void Init(int _top);
	void AddBullet(int x, int y, View &view);
	void Move(View &view);
	bool CheckCrush(int x, int y, View &view);
};
#endif
