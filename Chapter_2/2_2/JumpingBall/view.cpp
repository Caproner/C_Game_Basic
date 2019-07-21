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
	memset(views, 0, sizeof(views));
	memset(views_buffer, 0, sizeof(views_buffer));
}

void View::Flush()
{
	for(int i = 0; i < VIEW_HEIGHT; i++)
		for(int j = 0; j < VIEW_WIDTH; j++)
		{
			if(views[i][j] != views_buffer[i][j])
			{
				views[i][j] = views_buffer[i][j];
				gotoxy(i, j);
				putch(views[i][j]);
			}
		}
}

void View::Clear()
{
	for(int i = 0; i < VIEW_HEIGHT; i++)
		for(int j = 0; j < VIEW_WIDTH; j++)
			views_buffer[i][j] = ' ';
	Flush();
}

void View::Set(int x, int y, char c)
{
	views_buffer[x][y] = c;
}


void View::Delete(int x, int y)
{
	views_buffer[x][y] = ' ';
}

char View::Get(int x, int y)
{
	return views_buffer[x][y];
}
