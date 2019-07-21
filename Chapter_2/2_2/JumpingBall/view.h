#include "global.h"

#ifndef VIEW
#define VIEW
class View
{
	char views[VIEW_HEIGHT][VIEW_WIDTH];
	char views_buffer[VIEW_HEIGHT][VIEW_WIDTH];
public:
	
	View();
	void gotoxy(int x, int y);
	void Clear();
	void Set(int x, int y, char c);
	void Delete(int x, int y);
	char Get(int x, int y);
	void Flush();
};
#endif
