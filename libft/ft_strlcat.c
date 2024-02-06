/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:26:06 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/19 16:10:54 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	result;

	j = 0;
	i = 0;
	result = 0;
	if (src != NULL)
		result = ft_strlen(src);
	if (dst != NULL)
		i = ft_strlen((const char *)dst);
	if ((src == NULL || dst == NULL) && size == 0)
		return (result + i);
	if (size <= i)
		result += size;
	else
		result += i;
	while (src[j] && i + 1 < size)
		*(dst + i++) = *(src + j++);
	if (i < size)
		dst[i] = '\0';
	return (result);
}
