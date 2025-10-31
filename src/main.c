#include "../snake.h"

int	main()
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);

	start_game();

	endwin();
	echo();
}
