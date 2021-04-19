#include "minishell.h"

void 	env_norm_extra(t_dict *tmp, char **elem)
{
	size_t	size;

	size = ft_strlen(tmp->key) + ft_strlen(tmp->val) + 2;
	*elem = malloc(size);
	if (*elem == NULL)
		exit(cmd_err("malloc", NULL, "malloc error"));
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
		strs = ft_split(envp[i], '=');
		if (i == 0)
			new = dict_newentry(strs[0], strs[1]);
		else
			dict_addentry(&new, dict_newentry(strs[0], strs[1]));
		free(strs[2]);
		free(strs);
		i++;
	}
	return (new);
}

void	shell_init_shlvl(t_dict **envp)
{
	int		i;
	char	*itoa_tmp;

	if (dict_isin(envp, "SHLVL"))
	{
		i = ft_atoi((char *)dict_getval(envp, "SHLVL"));
		if (i >= 999)
		{
			cmd_err("warning", NULL, "shell level reached 1000, reset to 1");
			dict_chval(envp, "SHLVL", ft_strdup("1"));
		}
		else
		{
			itoa_tmp = ft_itoa(i + 1);
			dict_chval(envp, "SHLVL", ft_strdup(itoa_tmp));
			free(itoa_tmp);
		}
	}
	else
		dict_addentry(envp, dict_newentry(ft_strdup("SHLVL"), ft_strdup("1")));
}
