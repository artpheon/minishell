#include "minishell.h"

void 	io_init(t_io_params *p)
{
	p->tmpin = dup(0);
	p->tmpout = dup(1);
	p->fdin = dup(p->tmpin);
	p->fdout = dup(p->tmpout);
	if (p->tmpin < 0 || p->tmpout < 0 || p->fdin < 0 || p->fdout < 0)
		exit(cmd_err("dup", "initial configuration failed", strerror(errno)));
}

int	io_setin(t_cmd *cmd, int *in)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = -1;
	while ((cmd->infile)[i])
	{
		tmp = open((cmd->infile)[i], O_RDONLY);
		if (tmp < 0)
		{
			cmd_err(SHELL, (cmd->infile)[i], strerror(errno));
			return (1);
		}
		++i;
		if ((cmd->infile)[i])
			close(tmp);
	}
	if (tmp >= 0)
		*in = tmp;
	return (0);
}

void 	io_setout(t_cmd *cmd, int *out)
{
	int	i;

	i = 0;
	while ((cmd->outfile)[i])
	{
		if ((cmd->append_flag))
			*out = open((cmd->outfile)[i], O_WRONLY | O_APPEND | O_CREAT, 0644);
		else
			*out = open((cmd->outfile)[i], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (*out < 0)
			cmd_err(SHELL, (cmd->outfile)[i], strerror(errno));
		++i;
		if ((cmd->outfile)[i])
			close(*out);
	}
}

void	io_close(t_io_params *p)
{
	redir_streams(&p->tmpin, &p->tmpout);
	close(p->tmpin);
	close(p->tmpout);
}
