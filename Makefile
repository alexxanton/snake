NAME = snake
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -lncurses

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
