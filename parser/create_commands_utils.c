/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_commands_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:20:00 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:20:02 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	num_pipe(t_sh *sh)
{
	int	n;
	int	pipe;

	pipe = 0;
	n = 0;
	while (sh->args[n])
	{
		if (!(ft_strcmp(sh->args[n], "<PIPE>")))
			pipe++;
		n++;
	}
	sh->cmd_num = pipe + 1;
	return (pipe);
}

void	args_to_commands_pipe(t_sh *sh, int *n, const int *k, int i)
{
	(*n)++;
	sh->cmd[*k]->arg[i] = NULL;
}

void	init_command_params(t_sh *sh, int k)
{
	sh->cmd[k]->num_out = 0;
	sh->cmd[k]->num_in = 0;
}
