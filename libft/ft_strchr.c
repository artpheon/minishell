/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 07:26:29 by khermann          #+#    #+#             */
/*   Updated: 2020/11/21 17:40:53 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*chr;

	i = 0;
	while (s[i])
	{
		if (s[i++] == c)
		{
			chr = ((char *) &s[--i]);
			return (chr);
		}
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
