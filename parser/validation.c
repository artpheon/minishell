/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:13:50 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:13:51 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_pipe(t_sh *sh, int n)
{
	if (n == 0)
		return (1);
	if (sh->args[n + 1] == 0)
		return (1);
	if (!(ft_strcmp(sh->args[n + 1], "<PIPE>")))
		return (1);
	return (0);
}

int	valid_great(t_sh *sh, int n)
{
	if (sh->args[n + 1] == 0)
		return (1);
	if (!(ft_strcmp(sh->args[n + 1], "<GREAT>"))
		|| !(ft_strcmp(sh->args[n + 1], "<LESS>"))
		|| !(ft_strcmp(sh->args[n + 1], "<GREATGREAT>")
			|| !(ft_strcmp(sh->args[n + 1], "<PIPE>"))))
		return (1);
	return (0);
}

int	valid_less(t_sh *sh, int n)
{
	if (sh->args[n + 1] == 0)
		return (1);
	if (!(ft_strcmp(sh->args[n + 1], "<GREAT>"))
		|| !(ft_strcmp(sh->args[n + 1], "<LESS>"))
		|| !(ft_strcmp(sh->args[n + 1], "<GREATGREAT>")
			|| !(ft_strcmp(sh->args[n + 1], "<PIPE>"))))
		return (1);
	return (0);
}

int	valid_greatgreat(t_sh *sh, int n)
{
	if (sh->args[n + 1] == 0)
		return (1);
	if (!(ft_strcmp(sh->args[n + 1], "<GREAT>"))
		|| !(ft_strcmp(sh->args[n + 1], "<LESS>"))
		|| !(ft_strcmp(sh->args[n + 1], "<GREATGREAT>")
			|| !(ft_strcmp(sh->args[n + 1], "<PIPE>"))))
		return (1);
	return (0);
}

void	validation(t_sh *sh)
{
	int	n;

	n = 0;
	if (sh->args[0] == NULL)
		sh->check_null = 1;
	if (sh->tok.quote != 0)
		sh->ret_val = cmd_err(SHELL, NULL, "Syntax error: quotes");
	while (sh->args[n])
	{
		if (!(ft_strcmp(sh->args[n], "<PIPE>")))
			if (valid_pipe(sh, n))
				sh->ret_val = cmd_err(SHELL, NULL, "Syntax error near \"|\"");
		if (!(ft_strcmp(sh->args[n], "<GREAT>")))
			if (valid_great(sh, n))
				sh->ret_val = cmd_err(SHELL, NULL, "Syntax error near \">\"");
		if (!(ft_strcmp(sh->args[n], "<LESS>")))
			if (valid_less(sh, n))
				sh->ret_val = cmd_err(SHELL, NULL, "Syntax error near \"<\"");
		if (!(ft_strcmp(sh->args[n], "<GREATGREAT>")))
			if (valid_greatgreat(sh, n))
				sh->ret_val = cmd_err(SHELL, NULL, "Syntax error near \">>\"");
		n++;
	}
}
