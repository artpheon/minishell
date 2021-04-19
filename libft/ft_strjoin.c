/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:43:10 by khermann          #+#    #+#             */
/*   Updated: 2020/12/22 21:15:10 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	len = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[len])
		len++;
	while (s2[i])
		i++;
	len = len + i;
	str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	i = 0;
	len = 0;
	while (s1[i])
		str[len++] = s1[i++];
	i = 0;
	while (s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	return (str);
}
