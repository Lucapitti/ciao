SRC = "get_next_line_casa/get_next_line.c get_next_line_casa/get_next_line.h get_next_line_casa/get_next_line_utils.get_next_line_utils.c printf/ft_printf.c printf/ft_printf.h so_long.c"
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

all: $(NAME)

.c:
	$(CC) $(CFLAGS) $(SRC)

fclean: clean 
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re bonus