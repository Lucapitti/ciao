/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:18:51 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/12 19:19:19 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (!ptr1 || !ptr2)
		return (ptr1[i] - ptr2[i]);
	while (ptr1[i] == ptr2[i] && ptr1[i] && ptr2[i] && --n != 0)
	{
		i++;
	}
	if (ptr1[i] != ptr2[i])
		return ((ptr1[i] - ptr2[i]));
	return ('\0');
}
