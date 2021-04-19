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

int	fexec_cmd_cd(char **args, t_dict **envp)
{
	char	*pwd_old;
	char	*arg;

	if (args[1] == NULL)
		cmd_err("cd", NULL, EXARG);
	else
	{
		pwd_old = getcwd(NULL, 0);
		arg = fexec_subtild(args[1], dict_getval(envp, "HOME"));
		if (chdir(arg) != 0)
		{
			free(pwd_old);
			free(arg);
			cmd_err("cd", args[1], strerror(errno));
		}
		else
			return (cmd_cd_success(envp, pwd_old, arg));
	}
	return (1);
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
		while (args[1][i])
		{
			if (ft_isdigit(args[1][i]))
				i++;
			else
				exit(cmd_err("exit", args[1], "numeric argument required"));
		}
		i = ft_atoi(args[1]);
	}
	ft_putendl_fd("exit", 1);
	exit(i);
}

int	fexec_cmd_echo(char **args, t_dict **envp)
{
	int	w;
	int	newln;

	(void)envp;
	newln = 1;
	w = ft_skip_fl(args, 'n');
	if (w > 1)
		newln = 0;
	while (args[w])
	{
		ft_putstr_fd(args[w++], 1);
		if (args[w])
			ft_putchar_fd(' ', 1);
	}
	if (newln)
		ft_putchar_fd('\n', 1);
	return (0);
}
