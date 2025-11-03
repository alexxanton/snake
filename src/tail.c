#include "../snake.h"

void	tailadd_back(t_tail **tail, t_tail *new)
{
	t_tail	*last;

	if (!tail)
		return ;
	if (*tail)
	{
		last = taillast(*tail);
		last->next = new;
	}
	else
		*tail = new;
}

void	tailadd_front(t_tail **tail, t_tail *new)
{
	if (!tail)
		return ;
	if (*tail)
		new->next = *tail;
	*tail = new;
}

void	tailclear(t_tail **tail, void (*del)(void*))
{
	del(*tail);
}

void	taildelone(t_tail *tail, void (*del)(void*))
{
	del(tail);
}

void	tailiter(t_tail *tail, void (*f)(int, int))
{
	while (tail)
	{
		f(tail->x, tail->y);
		tail = tail->next;
	}
}

t_tail *taillast(t_tail *tail)
{
	while (tail)
	{
		tail = tail->next;
	}
	return (tail);
}

t_tail	*tailnew(int x, int y)
{
	t_tail	*new;

	new = malloc(sizeof(x) + sizeof(y));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

int	tailsize(t_tail *tail)
{
	int	i;

	i = 0;
	while (tail)
	{
		tail = tail->next;
		i++;
	}
	return (i);
}
