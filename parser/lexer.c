/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:58:57 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 15:59:00 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_main_cycle(t_sh *sh, const char *line)
{
	while (1)
	{
		if (sh->tok.n >= 1023 * sh->tok.realloc_count)
		{
			sh->tok.realloc_count++;
			sh->args = realloc_args(sh);
		}
		if (sh->tok.semicolon == 1)
			break ;
		if (line[sh->tok.k] == '\0')
			break ;
		sh->tok.i = 0;
		while (ft_isspace(line[sh->tok.k]))
			sh->tok.k++;
		if (line[sh->tok.k] == '\0')
			break ;
		sh->args[sh->tok.n] = malloc(sizeof(char) * 1024);
		if (line_to_args(sh, line) == 3)
			return ;
		sh->tok.n++;
	}
	sh->args[sh->tok.n] = NULL;
}

void	lexer(t_sh *sh, const char *line)
{
	sh->args = malloc(sizeof(char *) * 1024);
	sh->tok.n = 0;
	sh->tok.quote = 0;
	if (sh->tok.semicolon == 0)
	{
		sh->tok.k = 0;
		sh->tok.line = 0;
	}
	lexer_main_cycle(sh, line);
	sh->tok.count_free = sh->tok.n;
	if (sh->tok.semicolon == 1)
		sh->tok.semicolon = 0;
}
