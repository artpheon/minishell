#include "minishell.h"

void 	redir_streams(const int *in, const int *out)
{
	if (dup2(*in, STDIN_FILENO) == -1)
		exit(cmd_err("dup2", "stdin", strerror(errno)));
	if (dup2(*out, STDOUT_FILENO) == -1)
		exit(cmd_err("dup2", "stdout", strerror(errno)));
}

void	exec_fork_last(t_sh *sh, t_cmd *cmd, t_io_params *p)
{
	pid_t	pid;
	int		ret;

	io_setin(cmd, &p->fdin);
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

	io_setin(cmd, &p->fdin);
	io_setout(cmd, &p->fdout);
//	for (int i = 0; cmd->arg[i]; i++)
//		printf("args: %s\n", cmd->arg[i]);
//	for (int i = 0; cmd->infile[i]; i++)
//		printf("ins: %s\n", cmd->arg[i]);
//	for (int i = 0; cmd->outfile[i]; i++)
//		printf("outs: %s\n", cmd->arg[i]);
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

	pipe(p->fdpipe);
	io_setin(cmd, &p->fdin);
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
	else
	{
		waitpid(pid, &sh->background, 0);
		close(p->fdpipe[1]);
		close(p->fdin);
		p->fdin = p->fdpipe[0];
	}
}

void 	io_init(t_io_params *p)
{
	p->tmpin = dup(0);
	p->tmpout = dup(1);
	p->fdin = dup(p->tmpin);
	p->fdout = dup(p->tmpout);
	if (p->tmpin < 0 ||	p->tmpout < 0 || p->fdin < 0 || p->fdout < 0)
		exit(cmd_err("dup", "initial configuration failed", strerror(errno)));
}

void	executor(t_sh *sh)
{
	t_io_params	p;
	int			i;
	t_cmd		*command;

	i = 0;
	command = sh->cmd[i];
	io_init(&p);
	while (i++ < sh->cmd_num - 1)
	{
		exec_fork(sh, command, &p);
		command = sh->cmd[i];
	}
	if (sh->cmd_num == 1)
		exec_fork_only(sh, command, &p);
	else
		exec_fork_last(sh, command, &p);
	io_close(&p);
}
