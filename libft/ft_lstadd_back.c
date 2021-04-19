/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:37:50 by khermann          #+#    #+#             */
/*   Updated: 2020/11/23 16:41:48 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n;

	if (*lst)
	{
		n = *lst;
		while ((n->next) != 0)
			n = n->next;
		n->next = new;
		new->next = 0;
	}
	else
	{
		new->next = 0;
		*lst = new;
	}
}
