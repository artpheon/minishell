/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_line_to_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:08:47 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:08:49 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	line_to_args(t_sh *sh, const char *line)
{
	int	flag;

	sh->tok.realloc_count_n = 1;
	while (line[sh->tok.k])
	{
		flag = line_to_arg_qsl(sh, line);
		if (flag == 1)
			break ;
		else if (flag == 2)
			continue ;
		else if (flag == 3)
		{
			free(sh->args[sh->tok.n]);
			sh->args[sh->tok.n] = NULL;
			return (3);
		}
		else
			symbol_to_arg(sh, line);
	}
	return (0);
}

int	line_to_arg_qsl(t_sh *sh, const char *line)
{
	if (line[sh->tok.k] == '\'' && sh->tok.slash != 1)
		if (single_quotes(sh, line))
			return (2);
	if (line[sh->tok.k] == '\"' && sh->tok.quote != 1 )
		if (double_quotes(sh, line))
			return (2);
	if (line[sh->tok.k] == '\\' && sh->tok.quote != 1)
	{
		if (double_slash(sh, line))
			return (1);
		return (2);
	}
	return (line_to_arg_pipe(sh, line));
}

int	line_to_arg_pipe(t_sh *sh, const char *line)
{
	if (line[sh->tok.k] == '|' && line[sh->tok.k + 1] == '|')
	{
		if (sh->tok.quote != 0)
			;
		else
		{
			double_pipe(sh);
			return (1);
		}
	}
	if (line[sh->tok.k] == '|' && sh->tok.quote == 0)
	{
		single_pipe(sh);
		return (1);
	}
	return (line_to_arg_redirect(sh, line));
}

int	line_to_arg_redirect(t_sh *sh, const char *line)
{
	if (line[sh->tok.k] == '>' && line[sh->tok.k + 1]
		== '>' && sh->tok.quote == 0)
	{
		great_graet(sh);
		return (1);
	}
	if (line[sh->tok.k] == '>' && sh->tok.quote == 0)
	{
		graet(sh);
		return (1);
	}
	if (line[sh->tok.k] == '<' && sh->tok.quote == 0)
	{
		less(sh);
		return (1);
	}
	return (line_to_arg_extra(sh, line));
}

int	line_to_arg_extra(t_sh *sh, const char *line)
{
	if (line[sh->tok.k] == '$' && sh->tok.quote != 1)
	{
		if (get_env(sh, line))
			return (1);
		return (2);
	}
	if (ft_isspace(line[sh->tok.k]) && sh->tok.quote == 0)
	{
		spaces(sh, line);
		return (1);
	}
	if (sh->tok.slash == 1)
		slash_tmp(sh);
	if (line[sh->tok.k] == ';')
	{
		if (semicolon(sh, line))
			return (3);
		return (1);
	}
	return (0);
}
