/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:04:23 by khermann          #+#    #+#             */
/*   Updated: 2021/04/13 16:04:25 by khermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env_errno(t_sh *sh, const char *line)
{
	char	*str_errno;

	str_errno = ft_itoa(sh->background);
	ft_strlcat(sh->args[sh->tok.n], str_errno, 4096);
	sh->tok.k++;
	sh->tok.i += (int)ft_strlen(str_errno);
	free(str_errno);
	if (ft_isspace(line[sh->tok.k]) || line[sh->tok.k] == '\0')
		return (1);
	return (0);
}

int	dollar_to_args(t_sh *sh, const char *line)
{
	sh->args[sh->tok.n][sh->tok.i] = '$';
	sh->args[sh->tok.n][sh->tok.i + 1] = line[sh->tok.k];
	sh->tok.i++;
	if (ft_isspace(line[sh->tok.k]) || line[sh->tok.k] == '\0')
		return (0);
	return (0);
}

int	env_single_dollars(t_sh *sh, const char *line)
{
	if (line[sh->tok.k] == '?')
		return (get_env_errno(sh, line));
	else if (line[sh->tok.k] == '$')
		sh->ret_val = cmd_err(SHELL, NULL, "Syntax error: \"$$\"");
	else if (line[sh->tok.k] == ' ' || line[sh->tok.k] == '\0')
		sh->args[sh->tok.n][sh->tok.i++] = '$';
	else if (!(ft_strchr("><|\"\'", line[sh->tok.k])))
		return (dollar_to_args(sh, line));
	else
	{
		sh->args[sh->tok.n][sh->tok.i] = '$';
		sh->tok.i++;
		sh->args[sh->tok.n][sh->tok.i] = '\0';
		return (0);
	}
	sh->args[sh->tok.n][sh->tok.i] = '\0';
	return (0);
}

int	env_to_args(t_sh *sh, const char *line, int start, int len)
{
	char	*key;
	char	*tmp;

	key = malloc(sizeof(char) * (len));
	ft_strlcpy(key, (char *)&line[start], len);
	tmp = (char *)dict_getval(&sh->envp, key);
	free(key);
	if (tmp != NULL)
	{
		ft_strlcat(sh->args[sh->tok.n], tmp, 4096);
		sh->tok.i += (int) ft_strlen(tmp);
	}
	if (ft_isspace(line[sh->tok.k]) || line[sh->tok.k] == '\0')
		return (1);
	return (0);
}

int	get_env(t_sh *sh, const char *line)
{
	int	start;
	int	len;

	sh->args[sh->tok.n][sh->tok.i] = '\0';
	sh->tok.k++;
	start = sh->tok.k;
	len = 1;
	while (ft_isalnum(line[sh->tok.k]) || line[sh->tok.k] == '_')
	{
		sh->tok.k++;
		len++;
	}
	if (len == 1)
		return (env_single_dollars(sh, line));
	else
		return (env_to_args(sh, line, start, len));
}
