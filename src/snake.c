#include "../snake.h"
#include <stdbool.h>

void draw_snake(t_tail *tail)
{
	clear();
	mvaddch(tail->y, tail->x + (tail->x - 1), 'o');
	mvaddch(1, 1, ' ');
	refresh();
}

void update_snake(t_tail *tail, int hdir, int vdir)
{
	t_tail *next;

	while (tail)
	{
		if (tail->next)
		{
			next = tail->next;
			tail->x = next->x;
			tail->y = next->y;
			tail = next;
		}
		else
		{
			tail->x += hdir;
			tail->y += vdir;
			draw_snake(tail);
			break;
		}
	}
}

void start_game()
{
	bool loop = 1;
	int key, hdir = 1, vdir = 0;
	long px = 5, py = 5;
	t_tail *tail = malloc(sizeof(int));
	tail->x = 5;
	tail->y = 5;
	tail->next = NULL;

	while (loop)
	{
		px += hdir;
		py += vdir;
		//draw_snake(tail);
		update_snake(tail, hdir, vdir);
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
			case ' ':
				break;
			default:
				break;
		}
	}
}
