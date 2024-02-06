/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:09:22 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/20 13:09:24 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set_values(char *s, int n, int i)
{
	if (n > 9)
		ft_set_values(s, n / 10, i - 1);
	s[i] = ((n % 10) + '0');
}

static size_t	n_len(int n, int len)
{
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*final;
	size_t	len;

	if (n == -2147483648)
	{
		final = (char *)malloc(12);
		if (!final)
			return (NULL);
		ft_strlcpy(final, "-2147483648", 12);
		return (final);
	}
	len = n_len(n, 0);
	final = (char *)malloc((len + 1) * sizeof(char));
	if (!final)
		return (NULL);
	if (n < 0)
	{
		final[0] = '-';
		n *= -1;
	}
	ft_set_values(final, n, len - 1);
	final[len] = '\0';
	return (final);
}
