#include "minishell.h"

static int	cmd_cd_success(t_dict **envp, char *pwd_old, char *arg)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (dict_isin(envp, "OLDPWD"))
		dict_chval(envp, "OLDPWD", ft_strdup(pwd_old));
	else
		dict_addentry(envp,
			dict_newentry(ft_strdup("OLDPWD"), ft_strdup(pwd_old)));
	if (dict_isin(envp, "PWD"))
		dict_chval(envp, "PWD", ft_strdup(pwd));
	else
		dict_addentry(envp,
			dict_newentry(ft_strdup("PWD"), ft_strdup(pwd)));
	free(pwd);
	free(pwd_old);
	free(arg);
	return (0);
}

char	*fexec_cmd_cd_fix(char *arg, t_dict **envp, char *pwd_old)
{
	char	*new;

	if (arg == NULL)
	{
		if (dict_isin(envp, "HOME"))
			new = ft_strdup(dict_getval(envp, "HOME"));
		else
		{
			cmd_err(SHELL, "cd", "HOME not set");
			return (NULL);
		}
	}
	else if (ft_strncmp(arg, "-", 2) == 0)
	{
		if (dict_isin(envp, "OLDPWD"))
		{
			new = ft_strdup(dict_getval(envp, "OLDPWD"));
			ft_putendl_fd(new, 1);
		}
		else
		{
			free(pwd_old);
			cmd_err(SHELL, "cd", "OLDPWD not set");
			return (NULL);
		}
	}
	else
		new = fexec_subtild(arg, dict_getval(envp, "HOME"));
	return (new);
}

int	fexec_cmd_cd(char **args, t_dict **envp)
{
	char	*pwd_old;
	char	*arg;

	pwd_old = getcwd(NULL, 0);
	arg = fexec_cmd_cd_fix(args[1], envp, pwd_old);
	if (arg == NULL)
		return (1);
	if (chdir(arg) != 0)
	{
		free(pwd_old);
		free(arg);
		return (cmd_err("cd", args[1], strerror(errno)));
	}
	else
		return (cmd_cd_success(envp, pwd_old, arg));
}

int	fexec_cmd_help(char **args, t_dict **envp)
{
	(void)args;
	(void)envp;
	ft_putstr_fd("HELP MENU FOR SHELL\U0001F346 \U0001F346 \U0001F346 \n", 1);
	return (0);
}

int	fexec_cmd_exit(char **args, t_dict **envp)
{
	int	i;

	(void)envp;
	i = 0;
	if (args[1] != NULL)
	{
		if (ft_isdigit(args[1][0]) || args[1][0] == '-' || args[1][0] == '+')
			i = ft_atoi(args[1]);
		else
		{
			cmd_err("exit", args[1], "numeric argument required");
			exit(255);
		}
	}
	ft_putendl_fd("exit", 1);
	exit(i);
}
