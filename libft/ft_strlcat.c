/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 06:26:21 by khermann          #+#    #+#             */
/*   Updated: 2020/11/21 19:24:22 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	i;
	size_t	n;

	dst_size = 0;
	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (size == 0)
		return (src_size);
	while (dst_size < size && dest[dst_size] != '\0')
		dst_size++;
	if (dst_size == size)
		return (dst_size + src_size);
	i = dst_size;
	n = 0;
	while (i < (size - 1) && src[n] != '\0')
	{
		dest[i++] = src[n++];
	}
	dest[i] = '\0';
	return (src_size + dst_size);
}
