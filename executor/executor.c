#include "minishell.h"

void	exec_fork_last(t_sh *sh, t_cmd *cmd, t_io_params *p)
{
	pid_t	pid;
	int		ret;

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
	else
	{
		close(p->fdin);
		close(p->fdout);
		waitpid(pid, &sh->background, 0);
	}
}

void	exec_fork_only(t_sh *sh, t_cmd *cmd, t_io_params *p)
{
	pid_t	pid;
	int		ret;

	io_setout(cmd, &p->fdout);
	dup2(p->fdin, STDIN_FILENO);
	dup2(p->fdout, STDOUT_FILENO);
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
		else
		{
			close(p->fdin);
			close(p->fdout);
			waitpid(pid, &sh->background, 0);
		}
	}
}

void	exec_fork(t_sh *sh, t_cmd *cmd, t_io_params *p)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == 0)
	{
		close(p->fdpipe[0]);
		dup2(p->fdin, STDIN_FILENO);
		dup2(p->fdpipe[1], STDOUT_FILENO);
		ret = fexec_cmd(sh, cmd->arg);
		if (ret == 2)
			ret = fexec_bltin(sh, cmd->arg);
		exit(ret);
	}
	else if (pid < 0)
		exit(cmd_err("fork", cmd->arg[0], strerror(errno)));
	else
	{
		waitpid(pid, &sh->background, 0);
		close(p->fdpipe[1]);
		close(p->fdin);
		p->fdin = p->fdpipe[0];
	}
}

void	executor(t_sh *sh)
{
	t_io_params	p;
	int			i;
	t_cmd		*command;

	i = 0;
	command = sh->cmd[i];
	io_init(command, &p.fdin, &p);
	while (i < sh->cmd_num - 1)
	{
		pipe(p.fdpipe);
		io_setout(command, &p.fdpipe[1]);
		exec_fork(sh, command, &p);
		i++;
		command = sh->cmd[i];
	}
	if (sh->cmd_num == 1)
		exec_fork_only(sh, command, &p);
	else
	{
		io_setout(command, &p.fdout);
		dup2(p.fdin, STDIN_FILENO);
		dup2(p.fdout, STDOUT_FILENO);
		exec_fork_last(sh, command, &p);
	}
	io_close(&p);
}
