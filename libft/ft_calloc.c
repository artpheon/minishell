/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:33:14 by khermann          #+#    #+#             */
/*   Updated: 2020/11/21 18:56:23 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	i;
	char	*s;

	i = number * size;
	s = malloc(i);
	if (s == NULL)
		return (NULL);
	while (i > 0)
		s[(i--) - 1] = 0;
	return ((void *)s);
}
