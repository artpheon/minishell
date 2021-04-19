/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:13:13 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:13:16 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	symbol_to_arg(t_sh *sh, const char *line)
{
	sh->args[sh->tok.n][sh->tok.i] = line[sh->tok.k];
	sh->args[sh->tok.n][sh->tok.i + 1] = '\0';
	sh->tok.i++;
	sh->tok.k++;
}

char 	**realloc_args(t_sh *sh)
{
	char	**new_args;
	char	**tmp;

	new_args = calloc(sizeof(char *), (1024 * sh->tok.realloc_count));
	if (!new_args)
		exit (1);
	tmp = ft_memcpy(new_args, sh->args,
			sizeof(char *) * 1024 * (sh->tok.realloc_count - 1));
	free(sh->args);
	return (tmp);
}
