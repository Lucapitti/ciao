/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:57:19 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/12 19:37:00 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	rv;

	i = 0;
	negative = 0;
	rv = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 45)
	{
		i++;
		negative++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		rv = rv * 10 + str[i] - 48;
		i++;
	}
	if (negative % 2 == 1)
		return (rv * -1);
	return (rv);
}
