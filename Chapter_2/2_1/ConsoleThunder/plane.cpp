#include "plane.h"

void Plane::Init(int _x, int _y, int _left, int _right, int _top, int _bottom, View &view)
{
	x = _x;
	y = _y;
	b_left = _left;
	b_right = _right;
	b_top = _top;
	b_bottom = _bottom;
	
	view.Set(x, y, '*');
	view.Set(x + 1, y - 2, '*');
	view.Set(x + 1, y - 1, '*');
	view.Set(x + 1, y, '*');
	view.Set(x + 1, y + 1, '*');
	view.Set(x + 1, y + 2, '*');
	view.Set(x + 2, y - 1, '*');
	view.Set(x + 2, y + 1, '*');
}

int Plane::GetX()
{
	return x;
}

int Plane::GetY()
{
	return y;
}

void Plane::MoveLeft(View &view)
{
	if(y - 2 == b_left)
	{
		return;
	}
	view.Delete(x, y);
	view.Delete(x + 1, y + 2);
	view.Delete(x + 2, y - 1);
	view.Delete(x + 2, y + 1);
	view.Set(x, y - 1, '*');
	view.Set(x + 1, y - 3, '*');
	view.Set(x + 2, y - 2, '*');
	view.Set(x + 2, y, '*');
	y -= 1;
}

void Plane::MoveRight(View &view)
{
	if(y + 2 == b_right)
	{
		return;
	}
	view.Delete(x, y);
	view.Delete(x + 1, y - 2);
	view.Delete(x + 2, y - 1);
	view.Delete(x + 2, y + 1);
	view.Set(x, y + 1, '*');
	view.Set(x + 1, y + 3, '*');
	view.Set(x + 2, y, '*');
	view.Set(x + 2, y + 2, '*');
	y += 1;
}

void Plane::MoveTop(View &view)
{
	if(x == b_top)
	{
		return;
	}
	view.Delete(x + 1, y - 2);
	view.Delete(x + 1, y);
	view.Delete(x + 1, y + 2);
	view.Delete(x + 2, y - 1);
	view.Delete(x + 2, y + 1);
	view.Set(x - 1, y, '*');
	view.Set(x, y - 2, '*');
	view.Set(x, y - 1, '*');
	view.Set(x, y + 1, '*');
	view.Set(x, y + 2, '*');
	x -= 1;
}

void Plane::MoveBottom(View &view)
{
	if(x + 2 == b_bottom)
	{
		return;
	}
	view.Delete(x, y);
	view.Delete(x + 1, y - 2);
	view.Delete(x + 1, y - 1);
	view.Delete(x + 1, y + 1);
	view.Delete(x + 1, y + 2);
	view.Set(x + 2, y - 2, '*');
	view.Set(x + 2, y, '*');
	view.Set(x + 2, y + 2, '*');
	view.Set(x + 3, y - 1, '*');
	view.Set(x + 3, y + 1, '*');
	x += 1;
}

void Plane::Shot(View &view)
{}

void Plane::Destroy(View &view)
{
	for(int i = 0; i <= WIDTH + 1; i++)
	{
		view.Set(HEIGHT / 2 - 2, i, '-');
		view.Delete(HEIGHT / 2 - 1, i);
		view.Delete(HEIGHT / 2, i);
		view.Delete(HEIGHT / 2 + 1, i);
		view.Set(HEIGHT / 2 + 2, i, '-');
	}
	view.gotoxy(HEIGHT / 2, WIDTH / 2 - 4);
	printf("GAME  OVER");
	Sleep(3000);
	char input = getch();
	view.gotoxy(HEIGHT + 2, 0);
	exit(0);
}

bool Plane::CheckCrushBullet(BulletList &bulletList, View &view)
{
	return 	bulletList.CheckCrush(x, y, view) ||
			bulletList.CheckCrush(x + 1, y - 2, view) ||
			bulletList.CheckCrush(x + 1, y - 1, view) ||
			bulletList.CheckCrush(x + 1, y, view) ||
			bulletList.CheckCrush(x + 1, y + 1, view) ||
			bulletList.CheckCrush(x + 1, y + 2, view) ||
			bulletList.CheckCrush(x + 2, y - 1, view) ||
			bulletList.CheckCrush(x + 2, y + 1, view);
}

bool Plane::CheckCrush(int _x, int _y)
{
	return	((x == _x) && (y == _y)) || 
			((x + 1 == _x) && (y - 2 == _y)) ||
			((x + 1 == _x) && (y - 1 == _y)) ||
			((x + 1 == _x) && (y == _y)) ||
			((x + 1 == _x) && (y + 1 == _y)) ||
			((x + 1 == _x) && (y + 2 == _y)) ||
			((x + 2 == _x) && (y - 1 == _y)) ||
			((x + 2 == _x) && (y + 1 == _y)) ;
}
