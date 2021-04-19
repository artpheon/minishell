/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:52:18 by khermann          #+#    #+#             */
/*   Updated: 2021/04/15 16:52:19 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(t_sh *sh)
{
	int	n;

	n = 0;
	while (n <= sh->tok.count_free)
		free(sh->args[n++]);
	free(sh->args);
}

void 	free_cmd(t_sh *sh)
{
	int	k;

	k = 0;
	while (sh->cmd[k])
	{
		free(sh->cmd[k]->arg);
		free(sh->cmd[k]->outfile);
		free(sh->cmd[k]->infile);
		free(sh->cmd[k]);
		k++;
	}
	free(sh->cmd);
}
