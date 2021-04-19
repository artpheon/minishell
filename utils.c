#include "minishell.h"

int	cmd_err(char *cmd, char *arg, char *err_txt)
{
	write(STDOUT_FILENO, cmd, ft_strlen(cmd));
	write(STDOUT_FILENO, ": ", 2);
	if (arg)
	{
		write(STDOUT_FILENO, arg, ft_strlen(arg));
		write(STDOUT_FILENO, ": ", 2);
	}
	write(STDOUT_FILENO, err_txt, ft_strlen(err_txt));
	write(STDOUT_FILENO, "\n", 1);
	return (1);
}

void	free_2(void *p)
{
	int		i;
	char	**ptr;

	i = 0;
	ptr = p;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr[i]);
	free(p);
}

size_t	strlen_2(char **arr)
{
	size_t	size;

	size = 0;
	while (arr[size] != NULL)
	{
		size++;
	}
	return (size);
}
