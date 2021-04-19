/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_commands_memalloc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:43:34 by khermann          #+#    #+#             */
/*   Updated: 2021/04/15 16:43:36 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_inlen(t_sh *sh)
{
	int			len;
	int			n;

	len = 0;
	n = sh->tok.n;
	while (sh->args[n] && (ft_strcmp(sh->args[n], "<PIPE>") != 0))
	{
		if (ft_strcmp(sh->args[n], "<PIPE>") == 0)
			break ;
		if (ft_strcmp(sh->args[n], "<LESS>") == 0)
			len++;
		n++;
	}
	return (len);
}

int	cmd_outlen(t_sh *sh)
{
	int			len;
	int			n;

	len = 0;
	n = sh->tok.n;
	while (sh->args[n])
	{
		if (ft_strcmp(sh->args[n], "<PIPE>") == 0)
			break ;
		if ((ft_strcmp(sh->args[n], "<GREAT>") == 0)
			|| (ft_strcmp(sh->args[n], "<GREATGREAT>") == 0))
			len++;
		n++;
	}
	if (sh->args[n] != 0)
		sh->tok.n = n + 1;
	return (len);
}

int	cmd_argslen(t_sh *sh)
{
	int			len;
	int			n;

	len = 0;
	n = sh->tok.n;
	while (sh->args[n])
	{
		if (ft_strcmp(sh->args[n], "<PIPE>") == 0)
			break ;
		len++;
		n++;
	}
	return (len);
}
