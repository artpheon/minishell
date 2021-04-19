/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 00:15:32 by khermann          #+#    #+#             */
/*   Updated: 2021/04/20 00:15:34 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_sh *sh)
{
	struct termios	t;

	while (sh->running)
	{
		check_term();
		set_input_mode(&t);
		parser(sh);
		unset_input_mode(&t);
		if (!sh->ret_val)
			executor(sh);
		free_args(sh);
		free_cmd(sh);
		sh->ret_val = 0;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_sh	sh;

	(void)argc;
	(void)argv;
	setbuf(stdout, 0);
	signal(SIGINT, sig_handle);
	signal(SIGQUIT, sig_handle);
	signal(SIGTERM, sig_handle);
	shell_init(&sh, envp);
	minishell(&sh);
	return (0);
}
