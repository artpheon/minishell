/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:43:37 by khermann          #+#    #+#             */
/*   Updated: 2020/11/22 08:52:34 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_outside(void)
{
	char	*str;

	str = malloc(1);
	*str = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
		i++;
	if (start >= i)
		return (ft_outside());
	if (len >= (i - start))
		str = (char *)malloc(i - start + 1);
	else
		str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}
