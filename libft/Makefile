NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
