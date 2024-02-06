/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:27:48 by lpittigl          #+#    #+#             */
/*   Updated: 2023/11/16 19:30:22 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int min, int max)
{
	int *s;
	int i;
	int count;

	if (min >= max)
		return (0);
	i = max - min;
	count = 0;
	s = (int *)malloc(i * sizeof(int));
	if (s == NULL)
		return (NULL);
	if (min < max)
	{
		while(min < max)
		{
			s[count] = min;
			min++;
			count++;
		}
		return (s);
	}
	return (0);
}
