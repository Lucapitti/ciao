#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define RIGHT 1
#define LEFT -1
#define UP 2
#define DOWN -2
char *get_next_line(int fd);
int ft_strlen(char *c);
int ft_printf(char *s, ...);

typedef struct t_list
{
	int	row;
	int	column;
	struct t_list *next;
}	t_list;