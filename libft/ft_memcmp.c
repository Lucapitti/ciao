/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:44:29 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/12 17:44:33 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*frist;
	unsigned char	*second;
	size_t			i;

	frist = (unsigned char *)s1;
	second = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while ((frist[i] == second[i]) && i < n - 1)
		i++;
	return (frist[i] - second[i]);
}
