CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
CREATELIB = ar -rcs
ADDLIB = ranlib
SRCS = ft_printf.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CREATELIB) $(NAME) $^
	$(ADDLIB) $(NAME)

clean: 
	rm -f $(OBJECTS)

fclean: clean 
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re $(NAME)