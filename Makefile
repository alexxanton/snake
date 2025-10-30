NAME = snake
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	make -C libft
	cp libft/libft.a libft.a
	$(CC) $(CFLAGS) $(OBJECTS) libft.a -o $(NAME) -lncurses
	rm libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	make -C libft clean
	$(RM) $(OBJECTS)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all
