/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:38:31 by khermann          #+#    #+#             */
/*   Updated: 2020/11/23 17:35:01 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n;
	t_list	*next;

	n = *lst;
	while (n)
	{
		next = n->next;
		del(n->content);
		free(n);
		n = next;
	}
	*lst = 0;
}
