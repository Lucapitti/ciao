#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define RIGHT 1
#define LEFT -1
#define UP 2
#define DOWN -2

typedef struct t_list
{
	int	row;
	int	column;
	struct t_list *next;
}	t_list;

t_list	*ft_lstnew(int column, int row)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (head)
	{
		head->column = column;
		head->row = row;
		head->next = NULL;
	}
	return (head);
}

int	*read_map(char *file_name, t_list **entrance, int *n_collectibles)
{
	char	*temp;
	int		row;
	int		column;
	int		fd;
	int	old_column;

	row = 0;
	column = 0;
	fd = open (file_name, O_RDONLY);
	temp = get_next_line(fd);
	while (temp)
	{
		while (temp[column])
		{
			if (temp[column] == 'P')
			{
				(*entrance)->column = column;
				(*entrance)->row = row;
				(*entrance)->next = NULL;
			}
			if (temp[column] == 'C')
				(*n_collectibles)++;
			column++;
		}
		if (old_column != column)
		{
			ft_printf("Mappa non rettangolare");
			return (0);
		}
		old_column = column;
		free(temp);
		temp = get_next_line(fd);
		row++;
	}
	close (fd);
	return (row);
}

char	**init_map(char *file_name, int n_lines)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	map = (char **)malloc(n_lines * sizeof(char *));
	while (i < n_lines)
	{
		map[i] = get_next_line(fd);
		map[i][ft_strlen(map[i]) - 1] = 0;
	}
	close (fd);
	return (map);
}

char	**zero_matrix(int n_lines, char **map, int width)
{
	char	**visited;
	int		j;

	j = 0;
	visited = (char **)malloc(n_lines * sizeof(int *));
	while (j < n_lines)	
	{
		visited[j] = (char *)malloc(width + 1 * sizeof(int));
		bzero(visited[j], width + 1);
	}
}

int	update_lst(char **map, t_list *current, int which, int *n_collectibles)
{
	if (which == LEFT || which == RIGHT)
	{
		if (map[current->row][current->column + which] == 'C')
			*n_collectibles--;
		ft_lstaddback(ft_lstnew(current->column + which, current->row));
		if (map[current->row][current->column + which] == 'E')
			return (-1);
	}
	else
	{
		if (map[current->row + (which / 2)][current->column] == 'C')
			*n_collectibles--;
		ft_lstaddback(ft_lstnew(current->column, current->row + (which / 2)));
		if (map[current->row + (which / 2)][current->column] == 'E')
			return (-1);
	}
	return (0);
}
void	destroy_array(char **array, int n)
{
	while (n--)
		free (array[n]);
	free (array);
}

int	is_valid(char **map, t_list *entrance, int n_lines, int n_collectibles)
{
	char		**visited;
	int		exit_flag;
	int		width;
	t_list	*current;

	exit_flag = 1;
	width = ft_strlen(map[0]) - 1;
	visited = zero_matrix(n_lines, map, width);
	current = ft_lstnew(entrance->column, entrance->row);
	while (current && (n_lines || exit_flag))
	{
		if (current->column - 1 >= 0 && !visited[current->row][current->column - 1] && map[current->row][current->column - 1] != 1)
			{
				exit_flag += update_lst(map, current, LEFT, &n_collectibles);
				visited[current->row][current->column - 1]++;
			}
		if (current->column + 1 >= width && !visited[current->row][current->column + 1] && map[current->row][current->column + 1] != 1)
			{
				exit_flag += update_lst(map, current, RIGHT, &n_collectibles);
				visited[current->row][current->column + 1]++;
			}
		if (current->row - 1 >= 0 && !visited[current->row - 1][current->column] && map[current->row - 1][current->column] != 1)
			{
				exit_flag += update_lst(map, current, DOWN, &n_collectibles);
				visited[current->row - 1][current->column]++;
			}
		if (current->row + 1 >  n_lines && !visited[current->row + 1][current->column] && map[current->row + 1][current->column] != 1)
			{
				exit_flag += update_lst(map, current, UP, &n_collectibles);
				visited[current->row + 1][current->column]++;
			}
		current = current->next;
	}
	destroy_array(visited, n_lines);
	if (n_collectibles != 0 || exit_flag != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*entrance;
	char	**map;
	int		n_lines;
	int		n_collectibles;
	
	if (argc != 2)
	{
		ft_printf ("input non valido");
		return (0);
	}
	entrance = (t_list *)malloc(sizeof(t_list));
	n_lines = read_map(argv[1], &entrance, &n_collectibles);
	if (n_lines == 0)
		return (0);
	map = init_map(argv[1], n_lines);
	if (!is_valid(map, entrance, n_lines, n_collectibles))
	{
		destroy_array(map, n_lines);
		ft_printf ("Mappa non valida");
		return (0);
	}
	start_game(map);
}