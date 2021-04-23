#include "minishell.h"

int	fexec_cmd_env(char **args, t_dict **envp)
{
	if (args[1] != NULL)
		return (cmd_err("env", args[1], WRAR));
	else
		dict_print(envp, &prnt_keyisval);
	return (0);
}

int	fexec_cmd_unset(char **args, t_dict **envp)
{
	int	i;

	i = 1;
	if (args[i] == NULL)
		return (cmd_err("unset", NULL, "no variable specified"));
	while (args[i])
	{
		if (0 == dict_rmentry(envp, args[i]))
		{
			if (ft_strchr(args[i], '=') || ft_strchr(args[i], '+'))
				return (cmd_err("unset", args[i], "wrong identifier"));
		}
		i++;
	}
	return (0);
}

int	fexec_cmd_pwd(char **args, t_dict **envp)
{
	char	pwd[PATH_MAX];

	(void)args;
	(void)envp;
	if (getcwd(pwd, PATH_MAX))
		ft_putendl_fd(pwd, 1);
	else
		return (1);
	return (0);
}

int	fexec_cmd_nelly(char **args, t_dict **envp)
{
	(void)args;
	(void)envp;
	ft_putstr_fd("\x1b[1m\x1B[35m\x1b[40m", 1);
	ft_putendl_fd("Nelly is the baddest b!tch in the world.\x1B[0m", 1);
	return (0);
}
