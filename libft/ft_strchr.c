/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:23:09 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/18 17:35:16 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	if (s == '\0' && c != '\0')
		return (NULL);
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0' && *(s + i) == '\0')
		return ((char *)s + i);
	return (NULL);
}
