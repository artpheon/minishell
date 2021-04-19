/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:42:45 by khermann          #+#    #+#             */
/*   Updated: 2020/11/24 16:04:26 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i++] == c)
		if (s[i] == '\0')
			return (0);
	while (s[i])
	{
		if (s[i++] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] == '\0')
				count--;
			count++;
		}
	}
	count++;
	return (count);
}

char	**ft_free(char **arr, int count)
{
	int		i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
	return (0);
}

char	*ft_str(char *str, const char *s, char c, int i)
{
	int		n;

	n = 0;
	while (s[i + n] != c && s[i + n])
	{
		str[n] = s[i + n];
		n++;
	}
	str[n] = '\0';
	return (str);
}

char	**ft_arr(char **arr, char const *s, char c, int count)
{
	int		f;
	int		i;
	int		n;

	f = count;
	i = 0;
	count = 0;
	while (count < f)
	{
		while (s[i] == c)
			i++;
		n = 0;
		while (s[i + n] != c && s[i + n])
			n++;
		arr[count] = (char *)malloc(n + 1);
		if (!(arr[count]))
			return (ft_free(arr, count));
		arr[count] = ft_str(arr[count], s, c, i);
		while (s[i] != c && s[i])
			i++;
		i++;
		count++;
	}
	arr[count] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**arr;

	if (!s)
		return (0);
	if (s[0] == '\0')
	{
		arr = (char **)malloc(sizeof(char *));
		if (!arr)
			return (0);
		return (ft_arr(arr, s, c, 0));
	}
	count = ft_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (0);
	return (ft_arr(arr, s, c, count));
}
