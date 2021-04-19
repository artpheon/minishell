/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:12:43 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:12:45 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	great_graet(t_sh *sh)
{
	sh->args[sh->tok.n][sh->tok.i] = '\0';
	if (sh->args[sh->tok.n][0] != '\0')
		sh->tok.n++;
	else
		free(sh->args[sh->tok.n]);
	sh->args[sh->tok.n] = ft_strdup("<GREATGREAT>");
	sh->tok.k++;
	sh->tok.k++;
}

void	graet(t_sh *sh)
{
	sh->args[sh->tok.n][sh->tok.i] = '\0';
	if (sh->args[sh->tok.n][0] != '\0')
		sh->tok.n++;
	else
		free(sh->args[sh->tok.n]);
	sh->args[sh->tok.n] = ft_strdup("<GREAT>");
	sh->tok.k++;
}

void	less(t_sh *sh)
{
	sh->args[sh->tok.n][sh->tok.i] = '\0';
	if (sh->args[sh->tok.n][0] != 0)
		sh->tok.n++;
	else
		free(sh->args[sh->tok.n]);
	sh->args[sh->tok.n] = ft_strdup("<LESS>");
	sh->tok.k++;
}
