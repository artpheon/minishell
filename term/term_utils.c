/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:10:25 by khermann          #+#    #+#             */
/*   Updated: 2021/04/16 20:10:27 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	term_enter(t_buffer *b)
{
	ft_strlcat(b->buff, "\n", MAX_CANON);
	return (1);
}

void	term_symbol(t_buffer *b)
{
	write(1, b->symb, b->l);
	ft_strlcat(b->buff, b->symb, MAX_CANON);
}

void	term_tab(t_buffer *b)
{
	write(1, "\007", 1);
	b->c -= 1;
}

void	term_quit(t_buffer *b)
{
	b->buff[b->c] = '\0';
	b->c -= 1;
}

void	term_del(t_buffer *b)
{
	if (b->c != '\0')
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("ce", 0), 1, ft_putchar);
		b->buff[b->c - 1] = '\0';
		b->c -= 2;
	}
	else
	{
		write(1, "\007", 1);
		b->c -= 1;
	}
}
