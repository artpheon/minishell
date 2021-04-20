#include "minishell.h"

void	io_init(t_cmd *cmd, int *in, t_io_params *p)
{
	int	i;

	p->tmpin = dup(0);
	p->tmpout = dup(1);
	p->fdin = dup(p->tmpin);
	p->fdout = dup(p->tmpout);
	i = 0;
	while (cmd->infile[i])
	{
		*in = open(cmd->infile[i], O_RDONLY);
		if (*in < 0)
			cmd_err(cmd->infile[i], NULL, strerror(errno));
		i++;
		if (cmd->infile[i])
			close(*in);
	}
}

void 	io_setout(t_cmd *cmd, int *out)
{
	int	i;

	i = 0;
	while (cmd->outfile[i])
	{
		if (cmd->append_flag)
			*out = open(cmd->outfile[i], O_WRONLY | O_APPEND | O_CREAT, 0644);
		else
			*out = open(cmd->outfile[i], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (*out < 0)
			cmd_err(cmd->outfile[i], NULL, strerror(errno));
		i++;
		if (cmd->outfile[i])
			close(*out);
	}
}

void	io_close(t_io_params *p)
{
	dup2(p->tmpin, STDIN_FILENO);
	dup2(p->tmpout, STDOUT_FILENO);
	close(p->tmpin);
	close(p->tmpout);
}
