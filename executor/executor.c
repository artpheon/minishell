#include "minishell.h"

void	exec_fork_last(t_sh *sh, t_cmd *cmd, t_io_params *p)
{
	pid_t	pid;
	int		ret;

	if (io_setin(cmd, &p->fdin) != 1)
	{
		io_setout(cmd, &p->fdout);
		redir_streams(&p->fdin, &p->fdout);
		pid = fork();
		if (pid == 0)
		{
			ret = fexec_cmd(sh, cmd->arg);
			if (ret == 2)
				ret = fexec_bltin(sh, cmd->arg);
			exit(ret);
		}
		else if (pid < 0)
			exit(cmd_err("fork", cmd->arg[0], strerror(errno)));
		waitpid(pid, &sh->background, 0);
	}
	close(p->fdin);
	close(p->fdout);
}

void	exec_fork_only(t_sh *sh, t_cmd *cmd, t_io_params *p)
{
	pid_t	pid;
	int		ret;

	if (io_setin(cmd, &p->fdin) != 1)
	{
		io_setout(cmd, &p->fdout);
		redir_streams(&p->fdin, &p->fdout);
		sh->background = fexec_cmd(sh, cmd->arg);
		if (sh->background == 2)
		{
			pid = fork();
			if (pid == 0)
			{
				ret = fexec_bltin(sh, cmd->arg);
				exit(ret);
			}
			else if (pid < 0)
				exit(cmd_err("fork", cmd->arg[0], strerror(errno)));
			waitpid(pid, &sh->background, 0);
		}
	}
	close(p->fdin);
	close(p->fdout);
}

void	exec_fork(t_sh *sh, t_cmd *cmd, t_io_params *p)
{
	pid_t	pid;
	int		ret;

	pipe(p->fdpipe);
	if (io_setin(cmd, &p->fdin) != 1)
	{
		io_setout(cmd, &p->fdpipe[1]);
		pid = fork();
		if (pid == 0)
		{
			close(p->fdpipe[0]);
			redir_streams(&p->fdin, &p->fdpipe[1]);
			ret = fexec_cmd(sh, cmd->arg);
			if (ret == 2)
				ret = fexec_bltin(sh, cmd->arg);
			exit(ret);
		}
		else if (pid < 0)
			exit(cmd_err("fork", cmd->arg[0], strerror(errno)));
		waitpid(pid, &sh->background, 0);
	}
	close(p->fdpipe[1]);
	close(p->fdin);
	p->fdin = p->fdpipe[0];
}

void	executor(t_sh *sh)
{
	t_io_params	p;
	int			i;
	t_cmd		*command;

	i = 0;
	command = sh->cmd[i];
	if (exec_set_(&sh->envp, sh->cmd, sh->cmd_num))
		return ;
	args_to_low(sh->cmd, sh->cmd_num);
	io_init(&p);
	while (i < sh->cmd_num - 1)
	{
		exec_fork(sh, command, &p);
		++i;
		command = sh->cmd[i];
	}
	if (sh->cmd_num == 1)
		exec_fork_only(sh, command, &p);
	else
		exec_fork_last(sh, command, &p);
	io_close(&p);
}
