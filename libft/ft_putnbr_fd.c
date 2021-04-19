/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <khermann@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:16:56 by khermann          #+#    #+#             */
/*   Updated: 2020/11/21 17:45:20 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int a)
{
	int		size;

	size = 1;
	if (a < 0)
		a = a * -1;
	a = a / 10;
	while (a >= 1)
	{
		size++;
		a = a / 10;
	}
	return (size);
}

int	ft_power(int n)
{
	int	i;

	i = 1;
	while ((n--) > 0)
		i = i * 10;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		size;
	int		tmp;
	int		i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	size = ft_size(n);
	while ((size--) > 0)
	{
		i = size;
		tmp = n;
		while (i-- > 0)
			tmp /= 10;
		c = tmp % 10 + 48;
		write(fd, &c, 1);
	}
}
