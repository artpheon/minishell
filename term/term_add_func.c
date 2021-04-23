/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_add_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:40:27 by khermann          #+#    #+#             */
/*   Updated: 2021/04/16 20:40:28 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (c);
}

void	sig_handle(int signo)
{
	if (signo == SIGINT)
	{
		ft_putendl_fd("", 1);
	}
	if (signo == SIGQUIT)
	{
		ft_putendl_fd("Quit: 3", 1);
	}
	if (signo == SIGTERM)
		return ;
}

void	set_input_mode(struct termios *t)
{
	tcgetattr(0, t);
	t->c_lflag &= ~(ECHO);
	t->c_lflag &= ~(ICANON);
	t->c_lflag &= ~(ISIG);
	t->c_cc[VMIN] = 1;
	t->c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, t);
}

void	unset_input_mode(struct termios *t)
{
	tcgetattr(0, t);
	t->c_lflag |= ECHO;
	t->c_lflag |= ICANON;
	t->c_lflag |= ISIG;
	tcsetattr(0, TCSANOW, t);
}

void	check_term(void)
{
	char	*name;

	name = getenv("TERM");
	if (1 > tgetent(0, name))
	{
		ft_putstr_fd("No such terminal: ", 1);
		ft_putendl_fd(name, 1);
		exit(EXIT_FAILURE);
	}
	if (!isatty(0))
	{
		ft_putendl_fd("Not a terminal", 1);
		exit(EXIT_FAILURE);
	}
}
