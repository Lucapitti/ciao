/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:29:17 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/16 22:24:07 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*final;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	final = malloc(ft_strlen(s) + 1);
	if (final == NULL)
		return (0);
	while (s[i])
	{
		final[i] = f(i, s[i]);
		i++;
	}
	final[i] = 0;
	return (final);
}
