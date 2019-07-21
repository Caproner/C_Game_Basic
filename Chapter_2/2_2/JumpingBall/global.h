#include <cstdio>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <set>
#include <vector>
#include <algorithm>

#define HEIGHT 25
#define WIDTH 40
#define VIEW_HEIGHT 100
#define VIEW_WIDTH 100
#define BALL_SPEED 10
#define BOARD_X_MIN (HEIGHT - 3)
#define BOARD_X_MAX HEIGHT
#define INIT_BOARD_X BOARD_X_MAX
#define INIT_BOARD_Y_LEFT (WIDTH / 2 - 8)
#define INIT_BOARD_Y_RIGHT (WIDTH / 2 + 9)
#define INIT_BALL_X (INIT_BOARD_X - 1)
#define INIT_BALL_Y ((INIT_BOARD_Y_LEFT + INIT_BOARD_Y_RIGHT) / 2)
#define INIT_BALL_VX 1
#define INIT_BALL_VY 1
#define INIT_BLOCK_LEFT 1
#define INIT_BLOCK_RIGHT WIDTH
#define INIT_BLOCK_TOP 1
#define INIT_BLOCK_BOTTOM (INIT_BOARD_X - 10)
#define BLOCK_GENERATE_PROBABILITY 0.6


