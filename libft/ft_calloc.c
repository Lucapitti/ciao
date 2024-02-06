/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:01:23 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/11 18:17:17 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*b;

	if (count && size && (4294967295U / size <= count))
		return (NULL);
	b = (char *)malloc(size * count);
	if (b == NULL)
		return (NULL);
	ft_bzero(b, count * size);
	return ((void *)b);
}
