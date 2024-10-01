NAME = pipex
SRCS = 
OBJ = $(patsubst %.c, %.o, $(SRCS))
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
INCL = -I./

$(NAME) = $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
	