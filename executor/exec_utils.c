#include "minishell.h"

void	shell_init_set_funcs(t_sh *sh)
{
	sh->fexec_funcs[0] = &fexec_cmd_cd;
	sh->fexec_funcs[1] = &fexec_cmd_help;
	sh->fexec_funcs[2] = &fexec_cmd_exit;
	sh->fexec_funcs[3] = &fexec_cmd_echo;
	sh->fexec_funcs[4] = &fexec_cmd_env;
	sh->fexec_funcs[5] = &fexec_cmd_export;
	sh->fexec_funcs[6] = &fexec_cmd_unset;
	sh->fexec_funcs[7] = &fexec_cmd_pwd;
	sh->fexec_funcs[8] = &fexec_cmd_nelly;
	sh->cmd_str = malloc((sizeof(char *) * 11));
	sh->cmd_str[0] = ft_strdup("cd");
	sh->cmd_str[1] = ft_strdup("help");
	sh->cmd_str[2] = ft_strdup("exit");
	sh->cmd_str[3] = ft_strdup("echo");
	sh->cmd_str[4] = ft_strdup("env");
	sh->cmd_str[5] = ft_strdup("export");
	sh->cmd_str[6] = ft_strdup("unset");
	sh->cmd_str[7] = ft_strdup("pwd");
	sh->cmd_str[8] = ft_strdup("nelly");
	sh->cmd_str[9] = NULL;
}

char	*fexec_subtild(char *arg, char *path)
{
	char	*new;

	if (path && arg[0] == '~')
	{
		new = ft_strjoin(path, (arg + 1));
		return (new);
	}
	return (ft_strdup(arg));
}

void	shell_init(t_sh *sh, char **envp)
{
	sh->tok.semicolon = 0;
	sh->tok.line = 0;
	sh->tok.line_start = 0;
	sh->tok.slash = 0;
	sh->running = 1;
	sh->background = 0;
	sh->envp = envp_to_dict(envp);
	sh->h.arg = ft_calloc(sizeof(char *), 1024);
	sh->h.arg[1] = ft_strdup("");
	shell_init_shlvl(&sh->envp);
	shell_init_set_funcs(sh);
}

int	ft_only_ch(char const *str, char c)
{
	if (*str != c)
		return (0);
	while (*str == c)
	{
		str++;
	}
	if (*str != '\0')
		return (0);
	return (1);
}

int	ft_is_flag(char *args, char f)
{
	int	w;

	w = 0;
	if (args[w] == '-')
	{
		if (ft_only_ch((args + 1), f))
			return (0);
		return (1);
	}
	else
		return (1);
}
