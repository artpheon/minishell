/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:29:31 by khermann          #+#    #+#             */
/*   Updated: 2020/11/25 14:02:52 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*tmp_arr1;
	unsigned char	*tmp_arr2;
	size_t			i;

	i = 0;
	tmp_arr1 = (unsigned char *)arr1;
	tmp_arr2 = (unsigned char *)arr2;
	while (i < n)
	{
		if (tmp_arr1[i] != tmp_arr2[i])
			return (tmp_arr1[i] - tmp_arr2[i]);
		i++;
	}
	return (0);
}
