#include "minishell.h"

int	get_line_read(t_sh *sh, t_buffer *b)
{
	if (!strncmp(b->symb, "\033[A", 3))
		term_up(sh, b);
	else if (!strncmp(b->symb, "\033[B", 3))
		term_down(sh, b);
	else if (!strncmp(b->symb, "\033[D", 3)
		|| !strncmp(b->symb, "\033[C", 3))
		b->c -= b->l;
	else if (b->symb[0] == '\177')
		term_del(b);
	else if (b->symb[0] == '\011')
		term_tab(b);
	else if (b->symb[0] == '\004')
		term_d(b);
	else if (b->symb[0] == '\034')
		term_quit(b);
	else if (b->symb[0] == '\003')
		return (term_c(b));
	else if (b->symb[0] == '\n')
		return (term_enter(b));
	else if (!ft_isprint(b->symb[0]))
		b->c -= b->l;
	else
		term_symbol(b);
	b->c += b->l;
	return (0);
}

char	*get_line(t_sh *sh)
{
	t_buffer	b;

	b.buff = malloc(MAX_CANON);
	ft_bzero(b.buff, MAX_CANON);
	b.c = 0;
	while (1)
	{
		ft_bzero(b.symb, MAX_CANON);
		b.l = read(STDIN_FILENO, b.symb, MAX_CANON);
		if (b.c + b.l == MAX_CANON)
			return (b.buff);
		if (get_line_read(sh, &b))
			return (b.buff);
	}
}
