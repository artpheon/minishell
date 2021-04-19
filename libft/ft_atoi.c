/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:32:48 by khermann          #+#    #+#             */
/*   Updated: 2021/03/11 11:48:34 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	minus;

	i = 0;
	num = 0;
	minus = 1;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
		if (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				minus = -1;
	if (str[i] >= '0' && str[i] <= '9')
		while (str[i] >= '0' && str[i] <= '9')
			num = (10 * num + (str[i++] - 48));
	return (num * minus);
}
