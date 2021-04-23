/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:00:21 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:00:24 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	line_to_hist(t_sh *sh, char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]) && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return ;
	if (line[i + 1] == '\0')
		return ;
	i = MAX_CANON - 2;
	if (sh->h.arg[i - 1])
		free(sh->h.arg[i - 1]);
	while (i >= 2)
	{
		sh->h.arg[i + 1] = sh->h.arg[i];
		i--;
	}
	sh->h.arg[2] = ft_strdup(line);
	i = 0;
	while (sh->h.arg[2][i])
		i++;
	sh->h.arg[2][i - 1] = '\0';
}

void	init_parser_params(t_sh *sh)
{
	sh->h.i = 2;
	sh->h.flag_up = 0;
}

void	shell_prompt(void)
{
	ft_putstr_fd("\x1B[1;32m", 1);
	ft_putstr_fd(SHELL, 1);
	ft_putstr_fd("$ ", 1);
	ft_putstr_fd("\x1B[0m", 1);
}

void	parser(t_sh *sh)
{
	char	*line;

	line = NULL;
	init_parser_params(sh);
	if (sh->tok.line == 0)
	{
		shell_prompt();
		tputs(save_cursor, 1, ft_putchar);
		line = get_line(sh);
		ft_putendl_fd("", 1);
		line_to_hist(sh, line);
		if (sh->tok.line_start)
			free(sh->tok.line_start);
		sh->tok.line_start = line;
	}
	else
		line = sh->tok.line;
	sh->tok.realloc_count = 1;
	lexer(sh, (const char *) line);
	validation(sh);
	create_commands(sh);
}
