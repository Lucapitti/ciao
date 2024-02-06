/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:42:13 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/16 21:43:41 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (head)
	{
		head->content = data;
		head->next = NULL;
	}
	return (head);
}
