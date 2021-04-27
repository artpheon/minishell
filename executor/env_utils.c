#include "minishell.h"

void 	env_norm_extra(t_dict *tmp, char **elem)
{
	size_t	size;

	size = ft_strlen(tmp->key) + ft_strlen(tmp->val) + 2;
	*elem = malloc(size);
	if (*elem == NULL)
		exit(cmd_err(SHELL, "malloc", strerror(errno)));
	ft_strlcpy(*elem, tmp->key, size);
	ft_strlcat(*elem, "=", size);
	ft_strlcat(*elem, tmp->val, size);
}

char	**env_norm(t_dict **dict)
{
	char	**arr;
	int		i;
	size_t	size;
	t_dict	*tmp;

	size = dict_size(dict);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		exit(cmd_err("malloc", NULL, "malloc error"));
	i = 0;
	tmp = *dict;
	while (tmp)
	{
		if (tmp->val != NULL)
		{
			env_norm_extra(tmp, &arr[i]);
			i++;
		}
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

t_dict	*envp_to_dict(char **envp)
{
	t_dict	*new;
	char	**strs;
	int		i;

	i = 0;
	while (envp[i])
	{
		strs = ft_split_2(envp[i], '=');
		if (i == 0)
			new = dict_newentry(ft_strdup(strs[0]), ft_strdup(strs[1]));
		else
			dict_addentry(&new, dict_newentry(ft_strdup(strs[0]), ft_strdup(strs[1])));
		free_2(strs);
		++i;
	}
	return (new);
}

void	shell_init_shlvl(t_dict **envp)
{
	int		i;
	char	*tmp;

	if (dict_isin(envp, "SHLVL"))
	{
		i = ft_atoi((char *)dict_getval(envp, "SHLVL"));
		if (i >= 999)
		{
			cmd_err("warning", NULL, "shell level reached 1000, reset to 1");
			tmp = ft_strdup("1");
		}
		else if (i < 0)
			tmp = ft_strdup("1");
		else
			tmp = ft_itoa(i + 1);
		dict_chval(envp, "SHLVL", ft_strdup(tmp));
		free(tmp);
	}
	else
		dict_addentry(envp, dict_newentry(ft_strdup("SHLVL"), ft_strdup("1")));
}
