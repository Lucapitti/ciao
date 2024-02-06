/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:05:14 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/16 22:05:24 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*temp;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	temp = (char *)s;
	i = 0;
	s_len = ft_strlen(s);
	if (s_len < len)
		len = s_len;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (start < s_len && i < len)
	{
		substr[i] = temp[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
