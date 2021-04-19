/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:19:09 by khermann          #+#    #+#             */
/*   Updated: 2020/11/25 14:58:14 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	s2 = (char *)malloc(i + 1);
	if (!s2)
		return (0);
	s2[i] = '\0';
	while ((i--) > 0)
		s2[i] = f(i, s[i]);
	return (s2);
}
