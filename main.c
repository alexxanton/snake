#include <ncurses.h>

int	main()
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);

	echo();
}
