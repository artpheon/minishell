/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:29:47 by khermann          #+#    #+#             */
/*   Updated: 2020/11/19 05:02:17 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*tmp_dest;
	const unsigned char		*tmp_src;
	int						i;

	i = 0;
	tmp_dest = dest;
	tmp_src = src;
	if (!dest && !src)
		return (dest);
	while (n > 0)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
		n--;
	}
	return (dest);
}
