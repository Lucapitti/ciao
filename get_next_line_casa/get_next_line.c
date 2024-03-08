/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:23:38 by lpittigl          #+#    #+#             */
/*   Updated: 2024/03/08 19:30:42 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char *get_next_line(int fd)
{
	static char	*mem;
	char		*s;
	size_t		check;
	ssize_t		i;
	char		*ret;
	char 		*c;
	ssize_t		bytes_read;

	if (fd < 0 || fd >= 1000 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	if (mem)
	{
		s = (char *)malloc(len(mem) + 1);
		if (!s)
			return (NULL);
		ft_strlcpy(s, mem, BUFFER_SIZE);
		free (mem);
		while (s[i])
		{
			if (s[i] == '\n' || s[i] == -1)
			{
				mem = ft_substr(s, i + 1, len(s) - (i));
				ret = ft_substr(s, 0, i + 1);
				free (s);
				return (ret);
			}
			i++;
		}
	}
	else
		s = NULL;
	check = 1;
	while (check)
	{
		i = 0;
		c = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		bytes_read = read(fd, c, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			check--;
			free(c);
			break;
		}
		c[bytes_read] = 0;
		s = ft_strjoin(s, c);
		while (i < bytes_read && check)
		{
			if (c[i] == '\n')
				check--;
			i++;
		}
		free(c);
	}
	while (s && *(s + check) != 0 && *(s + check) != '\n' && *(s + check) != -1)
		check++;
	mem = ft_substr(s, check + 1, len(s) - (check));
	if (check - len(s) == 0)
		free(mem);
	ret = ft_substr(s, 0, check + 1);
	free (s);
	return (ret);
}

