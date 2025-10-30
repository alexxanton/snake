#include <ncurses.h>
#include "../snake.h"

void start_game()
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);

	echo();
}
