/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:43:51 by khermann          #+#    #+#             */
/*   Updated: 2020/11/26 19:21:17 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_empty(void)
{
	char	*str;

	str = malloc(sizeof(char *));
	str[0] = '\0';
	return (str);
}

int	ft_strtrim_lenstr(const char *s1, int i)
{
	while (s1[i + 1])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (!s1[i])
		return (ft_empty());
	start = i;
	i = ft_strtrim_lenstr(s1, i);
	while (s1[i] && ft_strchr(set, s1[i]))
		i--;
	end = i;
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
