#ifndef SNAKE_H
# define SNAKE_H
# include <ncurses.h>
# include <stdlib.h>

typedef struct s_tail
{
	int				x;
	int				y;
	struct s_tail	*next;
}					t_tail;
void start_game();

t_tail *tailnew(int x, int y);
void tailadd_front(t_tail **tail, t_tail *new);
int tailsize(t_tail *tail);
t_tail *taillast(t_tail *tail);
void tailadd_back(t_tail **tail, t_tail *new);
void taildelone(t_tail *tail, void (*del)(void*));
void tailclear(t_tail **tail, void (*del)(void*));
void tailiter(t_tail *tail, void (*f)(int, int));
t_tail *tailmap(t_tail *tail, void *(*f)(void *), void (*del)(void *));

#endif
