#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <limits.h>
# include <dirent.h>
# include "libft.h"
# include "dict.h"

# ifndef MAX_CANON
#  define MAX_CANON 1024
# endif
# define SHELL "shell"
# define ECMD "Command not found"
# define ESYNT "Syntax error near unexpected token"
# define WRAR "Wrong argument"

typedef struct s_tokens
{
	int		i;
	int		n;
	int		k;
	int		quote;
	int		quote_tmp;
	int		count_free;
	bool	slash;
	bool	semicolon;
	int		realloc_count;
	char	*line;
	char	*line_start;
}	t_tokens;

typedef struct s_cmd
{
	char	**arg;
	char	**outfile;
	int		num_out;
	bool	append_flag;
	char	**infile;
	int		num_in;
}	t_cmd;

typedef int	(*t_fp_cmds)(char **, t_dict **);

typedef struct s_hist
{
	char	**arg;
	int		i;
	bool	flag_up;
}	t_hist;

typedef struct s_sh
{
	char		**args;
	t_cmd		**cmd;
	t_tokens	tok;
	t_hist		h;
	t_dict		*envp;
	int			running;
	int			cmd_num;
	int			check_null;
	int			background;
	char		**cmd_str;
	t_fp_cmds	fexec_funcs[9];
	int			ret_val;
}	t_sh;

typedef struct s_io_params
{
	int	tmpin;
	int	tmpout;
	int	fdin;
	int	fdout;
	int	fdpipe[2];
}	t_io_params;

typedef struct s_buffer
{
	char	*buff;
	char	symb[MAX_CANON];
	int		c;
	int		l;
}	t_buffer;

extern int	g_exitsig;
int			ft_putchar(int c);
void		sig_handle(int signo);
void		check_term(void);
void		set_input_mode(struct termios *t);
void		unset_input_mode(struct termios *t);
char		*get_line(t_sh *sh);
void		minishell(t_sh *sh);
void		shell_init_shlvl(t_dict **envp);
void		shell_init_set_funcs(t_sh *sh);
void		shell_init(t_sh *sh, char **envp);
void		parser(t_sh *sh);
void		shell_prompt(void);
void		free_args(t_sh *sh);
void		free_cmd(t_sh *sh);
void		lexer(t_sh *sh, const char *line);
void		lexer_main_cycle(t_sh *sh, const char *line);
int			single_quotes(t_sh *sh, const char *line);
int			double_quotes(t_sh *sh, const char *line);
void		inc_into_quotes(t_sh *sh);
void		great_graet(t_sh *sh);
void		graet(t_sh *sh);
void		less(t_sh *sh);
void		single_pipe(t_sh *sh);
void		double_pipe(t_sh *sh);
void		spaces(t_sh *sh, const char *line);
void		slash(t_sh *sh);
int			double_slash(t_sh *sh, const char *line);
int			semicolon(t_sh *sh, const char *line);
void		slash_tmp(t_sh *sh);
void		symbol_to_arg(t_sh *sh, const char *line);
char		**realloc_args(t_sh *sh);
int			line_to_args(t_sh *sh, const char *line);
int			line_to_arg_qsl(t_sh *sh, const char *line);
int			line_to_arg_pipe(t_sh *sh, const char *line);
int			line_to_arg_redirect(t_sh *sh, const char *line);
int			line_to_arg_extra(t_sh *sh, const char *line);
int			get_env(t_sh *sh, const char *line);
int			env_to_args(t_sh *sh, const char *line, int start, int len);
int			get_env_errno(t_sh *sh, const char *line);
int			dollar_to_args(t_sh *sh, const char *line);
int			env_single_dollars(t_sh *sh, const char *line);
void		validation(t_sh *sh);
int			valid_pipe(t_sh *sh, int n);
int			valid_great(t_sh *sh, int n);
int			valid_less(t_sh *sh, int n);
int			valid_greatgreat(t_sh *sh, int n);
void		create_commands(t_sh *sh);
int			num_pipe(t_sh *sh);
int			cmd_argslen(t_sh *sh);
int			cmd_inlen(t_sh *sh);
int			cmd_outlen(t_sh *sh);
void		init_command_params(t_sh *sh, int k);
void		args_to_commands_pipe(t_sh *sh, int *n, const int *k, int i);
void		term_up(t_sh *sh, t_buffer *b);
void		term_down(t_sh *sh, t_buffer *b);
void		term_del(t_buffer *b);
void		term_tab(t_buffer *b);
void		term_quit(t_buffer *b);
int			term_c(t_buffer *b);
void		term_d(t_buffer *b);
int			term_enter(t_buffer *b);
void		term_symbol(t_buffer *b);
int			ft_only_ch(char const *str, char c);
int			ft_is_flag(char *args, char f);
void		free_2(void *p);
size_t		strlen_2(char **arr);
void		wtolow(char **word);
t_dict		*envp_to_dict(char **envp);
char		**env_norm(t_dict **dict);
bool		export_valcheck(char *str);
int			cmd_err(char *cmd, char *arg, char *err_txt);
char		**ft_split_2(char *str, char c);
void		io_init(t_io_params *p);
int			io_setin(t_cmd *cmd, int *in);
void		io_setout(t_cmd *cmd, int *out);
void		io_close(t_io_params *p);
void		redir_streams(const int *in, const int *out);
void		args_to_low(t_cmd **cmds, int num);
void		exec_fork_last(t_sh *sh, t_cmd *cmd, t_io_params *p);
void		exec_fork_only(t_sh *sh, t_cmd *cmd, t_io_params *p);
void		exec_fork(t_sh *sh, t_cmd *cmd, t_io_params *p);
int			exec_set__ext(t_dict **envp, char *arg);
int			exec_set_(t_dict **envp, t_cmd **cmd, int size);
void		executor(t_sh *sh);
char		*fexec_subtild(char *arg, char *path);
int			fexec_seekp(char **args, char **path, t_dict *envp);
int			fexec_bltin(t_sh *sh, char **args);
int			fexec_cmd(t_sh *sh, char **args);
int			fexec_cmd_cd(char **args, t_dict **envp);
int			fexec_cmd_help(char **args, t_dict **envp);
int			fexec_cmd_exit(char **args, t_dict **envp);
int			fexec_cmd_echo(char **args, t_dict **envp);
int			fexec_cmd_env(char **args, t_dict **envp);
int			fexec_cmd_export(char **args, t_dict **envp);
int			fexec_cmd_unset(char **args, t_dict **envp);
int			fexec_cmd_pwd(char **args, t_dict **envp);
int			fexec_cmd_nelly(char **args, t_dict **envp);

#endif
