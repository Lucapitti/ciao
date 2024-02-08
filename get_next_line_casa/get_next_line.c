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

#define BUFFER_SIZE 1

size_t	len(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != EOF)
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

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (final);
}

char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (start < len && i < len)
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
	int		i;
	char		*ret;
	char		 c[BUFFER_SIZE + 1];

	if (mem)
	{
		s = (char *)malloc(len(mem));
		if (!s)
			return (NULL);
		ft_strlcpy(s, mem, BUFFER_SIZE);
	}
	check = 1;
	while (check && read(fd, c, BUFFER_SIZE) > 0)
	{
		c[BUFFER_SIZE] = 0;
		i = 0;
		s = ft_strjoin(s, c);
		while (i < BUFFER_SIZE && check)
		{
			if (c[i] == '\n')
				check--;
			i++;
		}
	}
	while (s && s[check] != 0 && s[check] != '\n')
		check++;
	mem = ft_substr(s, check + 1, len(s) - (check + 1));
	ret = ft_substr(s, 0, check + 1);
	free (s);
	return (ret);
}
// fallo per me
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int fd;
    char *line;

    fd = open("get_next_line_utils.c", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("Line read: %s", line);
        free(line);
    }
    close(fd);

    return 0;
}
