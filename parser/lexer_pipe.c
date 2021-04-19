/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:11:18 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:11:21 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	double_pipe(t_sh *sh)
{
	sh->args[sh->tok.n][sh->tok.i] = '\0';
	if (sh->args[sh->tok.n][0] != '\0')
		sh->tok.n++;
	else
		free(sh->args[sh->tok.n]);
	sh->args[sh->tok.n] = ft_strdup("||");
	sh->tok.k++;
	sh->tok.k++;
}

void	single_pipe(t_sh *sh)
{
	sh->args[sh->tok.n][sh->tok.i] = '\0';
	if (sh->args[sh->tok.n][0] != '\0')
		sh->tok.n++;
	else
		free(sh->args[sh->tok.n]);
	sh->args[sh->tok.n] = ft_strdup("<PIPE>");
	sh->tok.k++;
}
