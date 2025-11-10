#include "../snake.h"

void clear_screen(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			mvaddch(i, j, ' ');
	}
}

void put_char(int y, int x, char c)
{
	mvaddch(y, x + (x - 1), c);
}
