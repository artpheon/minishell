/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_hist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:14:12 by khermann          #+#    #+#             */
/*   Updated: 2021/04/16 20:14:23 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	term_up(t_sh *sh, t_buffer *b)
{
	if (sh->h.flag_up)
		sh->h.i++;
	if (sh->h.arg[sh->h.i] == 0)
		sh->h.i--;
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tgetstr("ce", 0), 1, ft_putchar);
	b->buff[0] = '\0';
	ft_strlcpy(b->buff, sh->h.arg[sh->h.i], MAX_CANON);
	write(1, b->buff, ft_strlen(b->buff));
	b->c = (int) ft_strlen(b->buff) - b->l;
	sh->h.flag_up = 1;
}

void	term_down(t_sh *sh, t_buffer *b)
{
	if (sh->h.arg[sh->h.i - 1] != 0)
	{
		sh->h.i--;
		if (sh->h.arg[sh->h.i] == 0)
		{
			sh->h.i++;
			sh->h.flag_up = 0;
		}
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tgetstr("ce", 0), 1, ft_putchar);
		b->buff[0] = '\0';
		ft_strlcpy(b->buff, sh->h.arg[sh->h.i], MAX_CANON);
		write(1, b->buff, ft_strlen(b->buff));
		b->c = (int) ft_strlen(b->buff) - b->l;
		sh->h.flag_up = 1;
	}
}
