/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:52:29 by lpittigl          #+#    #+#             */
/*   Updated: 2024/02/03 17:52:30 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	len(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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
		final = (char *)malloc((len(s2) + 1) * sizeof(char));
	else
		final = (char *)malloc((len(s1) + len(s2) + 1) * sizeof(char));
	if (!final)
		return (NULL);
	if (s1)
		while (*(s1 + i))
		{
			final[i] = *(s1 + i);
			i++;
		}
	while (*(s2 + j))
	{
		final[i + j] = *(s2 + j);
		j++;
	}
	final[i + j] = 0;
	return (final);
}

char	*ft_substr(const char *s, size_t start)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = 0;
	if (!s)
		return (NULL);
	while (s[s_len] != '\n' && s[s_len])
		s_len++;
	if (s[s_len] == '\n')
		s_len++;
	substr = (char *)malloc((s_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (start < s_len && i < s_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
