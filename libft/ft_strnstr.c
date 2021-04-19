/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 07:14:25 by khermann          #+#    #+#             */
/*   Updated: 2020/11/30 14:45:49 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *str, size_t len)
{
	size_t	n;
	size_t	len_str;

	n = 0;
	if (ft_strlen(big) < ft_strlen(str)
		|| len < ft_strlen(str))
		return (0);
	if (str[0] == '\0')
		return ((char *)&big[0]);
	len_str = ft_strlen(str);
	while (big[n] != '\0' && n < len)
	{
		if (big[n] == str[0] && ((n + len_str) <= len))
		{
			if (ft_strncmp(&big[n], str, len_str) == 0)
				return ((char *)&big[n]);
		}
		n++;
	}
	return (NULL);
}
