#include "bullet.h"

void BulletList::Init(int _top)
{
	len = 0;
	b_top = _top;
	lastMoveTime = clock();
}

void BulletList::AddBullet(int x, int y, View &view)
{
	if(x < b_top)
	{
		return;
	}
	if((len != 0) && (b_list[len - 1].first == x) && (b_list[len - 1].second == y))
	{
		return;
	}
	b_list[len] = std::make_pair(x, y);
	len++;
	view.Set(x, y, '|');
}

void BulletList::Move(View &view)
{
	double waitTime = (double)(clock() - lastMoveTime) / CLOCKS_PER_SEC;
	if(waitTime < (1.0 / BULLET_SPEED))
	{
		return;
	}
	lastMoveTime = clock();
	for(int i = 0; i < len; i++)
	{
		view.Delete(b_list[i].first, b_list[i].second);
		if(b_list[i].first == b_top)
		{
			std::swap(b_list[i], b_list[len - 1]);
			i--;
			len--;
		}
		else
		{
			b_list[i].first--;
		}
	}
	for(int i = 0; i < len; i++)
	{
		view.Set(b_list[i].first, b_list[i].second, '|');
	}
}

bool BulletList::CheckCrush(int x, int y, View &view)
{
	for(int i = 0; i < len; i++)
	{
		if(b_list[i].first != x)
		{
			continue;
		}
		if(b_list[i].second != y)
		{
			continue;
		}
		view.Delete(b_list[i].first, b_list[i].second);
		std::swap(b_list[i], b_list[len - 1]);
		len--;
		return true;
	}
	return false;
}
