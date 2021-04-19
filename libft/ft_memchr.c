/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:29:15 by khermann          #+#    #+#             */
/*   Updated: 2020/11/18 14:56:15 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char		*tmp_arr;
	int					i;

	i = 0;
	tmp_arr = (unsigned char *)arr;
	while (n > 0)
	{
		if (tmp_arr[i] == (unsigned char)c)
			return ((void *)(&tmp_arr[i]));
		i++;
		n--;
	}
	return (0);
}
