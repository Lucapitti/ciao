/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:56:03 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/11 17:56:37 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	j = 0;
	if ((haystack == NULL && len == 0) || *needle == 0)
		return ((char *)haystack);
	while (*(haystack + j) && j <= (len - (int)ft_strlen(needle)))
	{
		i = 0;
		while (*(haystack + j + i) == *(needle + i)
			&& *(needle + i) && *(haystack + j + i) && i + j < len)
			i++;
		if (*(needle + i) == '\0')
			return ((char *)(haystack + j));
		j++;
	}
	return (NULL);
}
