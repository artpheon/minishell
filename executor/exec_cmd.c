#include "minishell.h"

static int	fexec_seekp_tryexpl(char **args, char **envp)
{
	char	**tmp;
	char	*newarg;
	DIR		*dir;

	if (ft_strncmp(*args, "./", 2) == 0 || ft_strncmp(*args, "/", 1) == 0
		|| ft_strncmp(*args, "../", 3) == 0)
	{
		if (execve(*args, args, envp) == -1)
			return (cmd_err(*args, NULL, strerror(2)));
	}
	else if (ft_strchr(*args, '/'))
	{
		tmp = ft_split(*args, '/');
		dir = opendir(tmp[0]);
		free_2(tmp);
		if (!dir)
			return (cmd_err(*args, NULL, strerror(2)));
		closedir(dir);
		newarg = ft_strjoin("./", *args);
		if (execve(newarg, args, envp) == -1)
			return (cmd_err(*args, NULL, strerror(2)));
	}
	return (0);
}

int	fexec_seekp(char **args, char **path, t_dict *envp)
{
	char	arg[2048];
	int		i;
	int		ret;

	arg[0] = 0;
	i = 0;
	ret = fexec_seekp_tryexpl(args, env_norm(&envp));
	if (ret == 0)
	{
		if (!path)
			return (1);
		while (path[i])
		{
			ft_strlcpy(arg, path[i], 2048);
			ft_strlcat(arg, "/", 2048);
			ft_strlcat(arg, args[0], 2048);
			if (execve(arg, args, env_norm(&envp)) == -1)
				i++;
			arg[0] = 0;
		}
		return (1);
	}
	else
		return (2);
}

int	fexec_cmd(t_sh *sh, char **args)
{
	int	i;
	int	cmd_n;

	if (args[0] == NULL)
		return (0);
	i = 0;
	cmd_n = (int)strlen_2(sh->cmd_str);
	while (i < cmd_n)
	{
		if (ft_strcmp(args[0], sh->cmd_str[i]) == 0)
			return (sh->fexec_funcs[i](args, &sh->envp));
		i++;
	}
	return (2);
}

int	fexec_bltin(t_sh *sh, char **args)
{
	char	**path;
	int		ret;

	path = ft_split(dict_getval(&sh->envp, "PATH"), ':');
	ret = fexec_seekp(args, path, sh->envp);
	if (path)
		free_2(path);
	if (ret == 1)
		cmd_err(SHELL, args[0], ECMD);
	return (2);
}
