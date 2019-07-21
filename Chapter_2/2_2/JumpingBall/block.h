#include "global.h"
#include "view.h"

#ifndef BLOCK
#define BLOCK
class Block
{
	std::set< std::pair<int, int> > blockSet;
public:
	void Init(View &view);
	void Erase(int x, int y, View &view);
};
#endif
