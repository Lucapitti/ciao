/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:23:38 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/30 20:23:40 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

size_t	len(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len] && s[len] != '\177')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	if (!s1)
		final = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	else
		final = (char *)malloc((len(s1) + BUFFER_SIZE + 1) * sizeof(char));
	if (!final)
		return (NULL);
	if (s1)
		while (*(s1 + i))
		{
			final[i] = *(s1 + i);
			i++;
		}
	while (*(s2 + j) != 0)
	{
		final[i + j] = *(s2 + j);
		j++;
	}
	final[i + j] = 0;
	free(s1);
	return (final);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}

char *get_next_line(int fd)
{
	static char	*mem;
	char		*s;
	size_t		check;
	int			i;
	char		*ret;
	char 		*c;
	size_t		bytes_read;

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
			if (s[i] == '\n')
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
	while (s && s[check] != 0 && s[check] != '\n' && s[check] != -1)
		check++;
	mem = ft_substr(s, check + 1, len(s) - (check));
	ret = ft_substr(s, 0, check + 1);
	free (s);
	return (ret);
}

#include <stdio.h>
#include <unistd.h>

int main(void) {
    int fd;
	int	i;
    char *line;

    fd = open("43_no_nl.txt", O_RDONLY);
	i = 10;
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while (i) {
		line = get_next_line(fd);
        printf("Line read: %s", line);
        free(line);
		i--;
    }
    close(fd);

    return 0;
}
