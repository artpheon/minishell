/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 23:22:46 by khermann          #+#    #+#             */
/*   Updated: 2020/11/21 17:31:11 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = 0;
	if (!dest || !src)
		return (0);
	while (src[src_size] != '\0')
		src_size++;
	if (size == 0)
		return (src_size);
	while (size > 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	dest[i] = '\0';
	return (src_size);
}
