#include "view.h"

void View::gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = y;
	pos.Y = x;
	SetConsoleCursorPosition(handle, pos);
}

View::View()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void View::Clear()
{
	system("cls");
	for(int i = 0; i < VIEW_HEIGHT; i++)
		for(int j = 0; j < VIEW_WIDTH; j++)
			views[i][j] = ' ';
}

void View::Set(int x, int y, char c)
{
	gotoxy(x, y);
	putch(c);
	views[x][y] = c;
}


void View::Delete(int x, int y)
{
	gotoxy(x, y);
	putch(' ');
	views[x][y] = ' ';
}

char View::Get(int x, int y)
{
	return views[x][y];
}
