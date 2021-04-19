/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:28:51 by khermann          #+#    #+#             */
/*   Updated: 2020/11/22 08:23:52 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			ch;
	unsigned char			*tmp_dest;
	const unsigned char		*tmp_src;
	unsigned int			i;

	i = 0;
	ch = (unsigned char)c;
	tmp_dest = dest;
	tmp_src = src;
	while (n > 0)
	{
		tmp_dest[i] = tmp_src[i];
		if (tmp_src[i] == ch)
			return (dest + i + 1);
		i++;
		n--;
	}
	return (0);
}
