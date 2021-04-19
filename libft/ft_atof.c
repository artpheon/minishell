/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:27:41 by khermann          #+#    #+#             */
/*   Updated: 2021/03/17 18:27:42 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	minus(char *str, int i)
{
	int	fac;

	fac = 1;
	if (str[i] == '-')
		fac = -1;
	return (fac);
}

float	ft_atof(char *str)
{
	float	atof;
	int		atoi;
	int		i;
	int		fac;

	atof = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	fac = minus(str, i);
	atoi = ft_atoi(str);
	i += ft_intlen(atoi);
	if (fac == -1)
		i++;
	if (str[i] != '.')
		return (atoi);
	i++;
	while (ft_isdigit(str[i]))
	{
		fac *= 10;
		atof = atof * 10 + str[i] - 48;
		i++;
	}
	atof = atof / fac;
	return (atoi + atof);
}
