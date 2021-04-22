#include "minishell.h"

void	io_setin(t_cmd *cmd, int *in)
{
	int	i;
	int tmp;

	i = 0;
	tmp = -1;
	while (cmd->infile[i])
	{
		tmp = open(cmd->infile[i], O_RDONLY);
		if (tmp < 0)
		{
			cmd_err(cmd->infile[i], NULL, strerror(errno));
			break ;
		}
		++i;
		if (cmd->infile[i])
			close(tmp);
	}
	if (tmp >= 0)
		*in = tmp;
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
		++i;
		if (cmd->outfile[i])
			close(*out);
	}
}

void	io_close(t_io_params *p)
{
	redir_streams(&p->tmpin, &p->tmpout);
	close(p->tmpin);
	close(p->tmpout);
}
