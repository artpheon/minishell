/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:12:25 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:12:27 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inc_into_quotes(t_sh *sh)
{
	sh->args[sh->tok.n][sh->tok.i] = '\'';
	sh->args[sh->tok.n][sh->tok.i + 1] = '\0';
	sh->tok.i++;
	sh->tok.k++;
}

int	single_quotes(t_sh *sh, const char *line)
{
	if (sh->tok.quote == 1)
	{
		sh->tok.quote = 0;
		sh->tok.k++;
		return (1);
	}
	else if (sh->tok.quote == 2)
		inc_into_quotes(sh);
	else
	{
		sh->tok.k++;
		if (line[sh->tok.k] == '\'')
		{
			sh->tok.k++;
			return (1);
		}
		else
		{
			sh->tok.quote = 1;
			if (line[sh->tok.k] == '\0')
				sh->args[sh->tok.n][sh->tok.i] = '\0';
		}
	}
	return (1);
}

int	double_quotes(t_sh *sh, const char *line)
{
	if (sh->tok.quote == 2)
	{
		sh->tok.quote = 0;
		sh->tok.k++;
		return (1);
	}
	else if (sh->tok.quote == 1)
		inc_into_quotes(sh);
	else
	{
		sh->tok.k++;
		if (line[sh->tok.k] == '\"')
		{
			sh->tok.k++;
			return (1);
		}
		else
		{
			sh->tok.quote = 2;
			if (line[sh->tok.k] == '\0')
				sh->args[sh->tok.n][sh->tok.i] = '\0';
		}
	}
	return (1);
}
