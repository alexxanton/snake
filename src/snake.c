#include "../snake.h"
#include <stdbool.h>

void draw_snake(int y, int x)
{
	clear();
	mvaddch(y, x + (x - 1), 'o');
	mvaddch(1, 1, ' ');
	refresh();
}

void start_game()
{
	bool loop = 1;
	int key, hdir = 1, vdir = 0;
	int px = 5, py = 5;

	while (loop)
	{
		px += hdir;
		py += vdir;
		draw_snake(py, px);
		halfdelay(5);
		key = getch();
		switch (key)
		{
			case KEY_UP:
				vdir = -1;
				hdir = 0;
				break;
			case KEY_DOWN:
				vdir = 1;
				hdir = 0;
				break;
			case KEY_LEFT:
				hdir = -1;
				vdir = 0;
				break;
			case KEY_RIGHT:
				hdir = 1;
				vdir = 0;
				break;
			case 'q':
				loop = 0;
				break;
			default:
				break;
		}
	}
}
