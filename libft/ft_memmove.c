/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:30:04 by khermann          #+#    #+#             */
/*   Updated: 2020/11/21 17:41:31 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;
	size_t				i;

	tmp_dest = dest;
	tmp_src = src;
	if (dest == 0 && src == 0)
		return (dest);
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			tmp_dest[n] = tmp_src[n];
		}
		return (dest);
	}
	i = 0;
	while (n > 0)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
		n--;
	}
	return (dest);
}
