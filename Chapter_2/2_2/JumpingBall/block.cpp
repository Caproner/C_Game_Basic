#include "block.h"

void Block::Init(View &view)
{
	blockSet.clear();
	for(int i = INIT_BLOCK_TOP; i <= INIT_BLOCK_BOTTOM; i++)
		for(int j = INIT_BLOCK_LEFT; j <= INIT_BLOCK_RIGHT; j++)
		{
			double p = rand() % 1000;
			p /= 1000;
			if(p < BLOCK_GENERATE_PROBABILITY)
			{
				view.Set(i, j, 'B');
				blockSet.insert(std::make_pair(i, j));
			}
		}
}
void Block::Erase(int x, int y, View &view)
{
	blockSet.erase(std::make_pair(x, y));
	view.Delete(x, y);
}
