#include "minishell.h"

int	fexec_cmd_env(char **args, t_dict **envp)
{
	if (args[1] != NULL)
		return (cmd_err("env", args[1], WRAR));
	else
		dict_print(envp, &prnt_keyisval);
	return (0);
}

static void	fexec_cmd_export_cat(char *key, char *val, t_dict **envp, int f)
{
	if (!dict_isin(envp, key))
		dict_addentry(envp, dict_newentry(ft_strdup(key), ft_strdup(val)));
	else
	{
		if (!f)
			dict_chval(envp, key, ft_strdup(val));
		else
		{
			if (dict_getval(envp, key) == NULL)
				dict_chval(envp, key, ft_strjoin("", val));
			else
				dict_chval(envp, key, ft_strjoin(dict_getval(envp, key), val));
		}
	}
}

static void	fexec_cmd_export_add(char *arg, t_dict **envp)
{
	char	**sargs;
	int		f;
	char	*key;

	f = 0;
	sargs = ft_split_2(arg, '=');
	if (ft_strchr(sargs[0], '+'))
	{
		f = 1;
		key = ft_strtrim(sargs[0], "+");
	}
	else
		key = sargs[0];
	fexec_cmd_export_cat(key, sargs[1], envp, f);
	if (f)
		free(key);
	free_2(sargs);
}

static void	cmd_export_ext(char *arg, t_dict **envp)
{
	if (!ft_strchr(arg, '='))
	{
		if (!dict_isin(envp, arg))
			dict_addentry(envp, dict_newentry(ft_strdup(arg), NULL));
	}
	else
		fexec_cmd_export_add(arg, envp);
}

int	fexec_cmd_export(char **args, t_dict **envp)
{
	int	i;

	if (args[1] == NULL)
		dict_print(envp, prnt_declx);
	else
	{
		i = 1;
		while (args[i])
		{
			if (export_valcheck(args[i]) == false)
			{
				i++;
				cmd_err("export", args[i], "is not a valid identifier");
				continue ;
			}
			cmd_export_ext(args[i], envp);
			i++;
		}
	}
	return (0);
}
