/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:16:46 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:16:48 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_great(t_sh *sh, int *n, const int *k, int *i)
{
	(*n)++;
	sh->cmd[*k]->outfile[sh->cmd[*k]->num_out] = sh->args[*n];
	sh->cmd[*k]->num_out++;
	sh->cmd[*k]->append_flag = 0;
	if (sh->args[*n] == NULL)
		(*n)--;
	(*i)--;
}

int	cmd_less(t_sh *sh, int *n, const int *k, int *i)
{
	(*n)++;
	sh->cmd[*k]->infile[sh->cmd[*k]->num_in] = sh->args[*n];
	sh->cmd[*k]->num_in++;
	if (sh->args[*n] == NULL)
		(*n)--;
	(*i)--;
	return (0);
}

void	cmd_greatgreat(t_sh *sh, int *n, const int *k, int *i)
{
	(*n)++;
	sh->cmd[*k]->outfile[sh->cmd[*k]->num_out] = sh->args[*n];
	sh->cmd[*k]->num_out++;
	sh->cmd[*k]->outfile[1] = NULL;
	sh->cmd[*k]->append_flag = 1;
	if (sh->args[*n] == NULL)
		(*n)--;
	(*i)--;
}

void	args_to_commands(t_sh *sh, int *n, int *k, int i)
{
	while (++i || 1)
	{
		if (sh->args[*n] == NULL)
		{
			sh->cmd[*k]->arg[i] = 0;
			break ;
		}
		if (!(ft_strcmp(sh->args[*n], "<PIPE>")))
		{
			args_to_commands_pipe(sh, n, k, i);
			break ;
		}
		if (!(ft_strcmp(sh->args[*n], "<GREAT>")))
			cmd_great(sh, n, k, &i);
		else if (!(ft_strcmp(sh->args[*n], "<LESS>")))
			cmd_less(sh, n, k, &i);
		else if (!(ft_strcmp(sh->args[*n], "<GREATGREAT>")))
			cmd_greatgreat(sh, n, k, &i);
		else
			sh->cmd[*k]->arg[i] = sh->args[*n];
		(*n)++;
	}
}

void	create_commands(t_sh *sh)
{
	int	n;
	int	k;
	int	num_command;

	num_command = num_pipe(sh) + 1;
	sh->tok.n = 0;
	sh->cmd = malloc(sizeof(t_cmd *) * (num_command + 2));
	if (!(sh->cmd))
		exit(1);
	n = 0;
	k = -1;
	while (++k <= num_command)
	{
		sh->cmd[k] = malloc(sizeof(t_cmd));
		if (!(sh->cmd[k]))
			exit(1);
		init_command_params(sh, k);
		sh->cmd[k]->arg = ft_calloc(sizeof (char *), cmd_argslen(sh) + 5);
		sh->cmd[k]->infile = ft_calloc(sizeof(char *), cmd_inlen(sh) + 5);
		sh->cmd[k]->outfile = ft_calloc(sizeof(char *), cmd_outlen(sh) + 5);
		if (!(sh->cmd[k]->arg) || !sh->cmd[k]->infile || !sh->cmd[k]->infile)
			exit (1);
		args_to_commands(sh, &n, &k, -1);
	}
	sh->cmd[k] = 0;
}
