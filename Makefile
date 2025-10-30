NAME = snake
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

#$(NAME): $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $< -0 $@ -lncurses

all: $(NAME)

clean:
	make -C libft clean
	$(RM) $(OBJECTS)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all
