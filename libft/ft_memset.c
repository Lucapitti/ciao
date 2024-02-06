/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:54:28 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/08 16:09:00 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			count;

	temp = (unsigned char *) b;
	count = 0;
	while (count < len)
	{
		temp[count] = (unsigned char) c;
		count++;
	}
	return (b);
}
