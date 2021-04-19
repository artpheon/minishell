/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:02:50 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:02:52 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	spaces(t_sh *sh, const char *line)
{
	sh->args[sh->tok.n][sh->tok.i] = '\0';
	while (ft_isspace(line[sh->tok.k]))
		sh->tok.k++;
	sh->tok.k--;
}

void	slash(t_sh *sh)
{
	sh->tok.quote_tmp = sh->tok.quote;
	sh->tok.quote = 1;
	sh->tok.slash = 1;
	sh->tok.k++;
}

int	double_slash(t_sh *sh, const char *line)
{
	if (line[sh->tok.k + 1] == '\0')
	{
		sh->args[sh->tok.n][sh->tok.i] = '\0';
		sh->tok.k++;
		return (1);
	}
	slash(sh);
	if (sh->tok.quote_tmp == 2 && line[sh->tok.k]
		!= '\\' && line[sh->tok.k] != '\"')
	{
		sh->args[sh->tok.n][sh->tok.i] = '\\';
		sh->tok.i++;
	}
	return (0);
}

int	semicolon(t_sh *sh, const char *line)
{
	if (sh->tok.i != 0)
	{
		sh->args[sh->tok.n][sh->tok.i] = '\0';
		sh->tok.k++;
	}
	else
	{
		free(sh->args[sh->tok.n]);
		sh->args[sh->tok.n] = 0;
		sh->tok.k++;
	}
	sh->tok.semicolon = 1;
	if (line[sh->tok.k] == ';' || (sh->tok.n == 0 && sh->tok.i == 0))
	{
		sh->ret_val = cmd_err(SHELL, NULL, ESYNT " \";\"");
		sh->tok.semicolon = 0;
		return (1);
	}
	sh->tok.line = (char *)&line[sh->tok.k];
	return (0);
}

void	slash_tmp(t_sh *sh)
{
	sh->tok.slash = 0;
	sh->tok.quote = sh->tok.quote_tmp;
}
