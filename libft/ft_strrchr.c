/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:37:06 by khermann          #+#    #+#             */
/*   Updated: 2020/11/18 16:07:12 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		f;
	char	*chr;

	i = 0;
	f = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			chr = (char *)&s[i];
			f = 1;
		}
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	if (f == 1)
		return (chr);
	return (NULL);
}
