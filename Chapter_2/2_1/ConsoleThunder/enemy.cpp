#include "enemy.h"

void Enemy::Init(int _y, int _bottom, View &view)
{
	x = 1;
	y = _y;
	b_bottom = _bottom;
	speed = ENEMY_SPEED_MIN;
	lastMoveTime = clock();
	view.Set(x, y, '@');
}

void Enemy::Move(View &view)
{
	double waitTime = (double)(clock() - lastMoveTime) / CLOCKS_PER_SEC;
	if(waitTime < (1.0 / speed))
	{
		return;
	}
	lastMoveTime = clock();
	if(x == b_bottom)
	{
		this->Revive(view, false);
	}
	view.Delete(x, y);
	x++;
	view.Set(x, y, '@');
}

void Enemy::Revive(View &view, bool isShooted)
{
	view.Delete(x, y);
	if(isShooted)
	{
		speed += ENEMY_SPEEDUP_PER_SCORE;
		speed = std::min(speed, (double)(ENEMY_SPEED_MAX));
	}
	x = 1;
	while(true)
	{
		y = rand() % (WIDTH - 5) + 3;
		if(view.Get(x, y) == ' ')
		{
			break;
		}
	}
	view.Set(x, y, '@');
}

int Enemy::GetX()
{
	return x;
}

int Enemy::GetY()
{
	return y;
}
