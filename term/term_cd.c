/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:16:10 by khermann          #+#    #+#             */
/*   Updated: 2021/04/16 20:16:11 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	term_d(t_buffer *b)
{
	struct termios t;

	if (b->c == 0)
	{
		tcgetattr(0, &t);
		t.c_lflag |= ECHO;
		t.c_lflag |= ICANON;
		t.c_lflag |= ISIG;
		tcsetattr(0, TCSANOW, &t);
		ft_putendl_fd("exit", 1);
		exit(EXIT_SUCCESS);
	}
	write(1, "\007", 1);
	b->c -= 1;
}

int	term_c(t_buffer *b)
{
	b->buff[0] = '\0';
	return (1);
}
