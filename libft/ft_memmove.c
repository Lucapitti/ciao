/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:38:18 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/08 16:34:13 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*srcs;

	dest = (unsigned char *) dst;
	srcs = (const unsigned char *) src;
	if (dest == NULL && srcs == NULL)
		return (dst);
	if (dest < srcs || dest >= srcs + len)
	{
		while (len-- > 0)
		{
			*dest = *srcs;
			dest++;
			srcs++;
		}
	}
	else
	{
		dest += len;
		srcs += len;
		while (len-- > 0)
			*(--dest) = *(--srcs);
	}
	return (dst);
}
