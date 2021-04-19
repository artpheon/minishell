#include "dict.h"

void	prnt_keyisval(t_dict *lst)
{
	if (lst->val)
		printf("%s=%s\n", (char *)lst->key, (char *)lst->val);
}

void	prnt_declx(t_dict *lst)
{
	if (lst->val)
		printf("declare -x %s=\"%s\"\n", (char *)lst->key, (char *)lst->val);
	else
		printf("declare -x %s\n", (char *)lst->key);
}

void	dict_print(t_dict **list, void (*format)(t_dict *))
{
	t_dict	*runner;

	runner = *list;
	while (runner)
	{
		format(runner);
		runner = runner->next;
	}
}

int	dict_chval(t_dict **dict, void *key, void *newval)
{
	t_dict	*tmp;

	tmp = *dict;
	while (tmp != NULL)
	{
		if (ft_strcmp(key, tmp->key) == 0)
		{
			free(tmp->val);
			tmp->val = newval;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	dict_size(t_dict **dict)
{
	int		size;
	t_dict	*tmp;

	size = 0;
	tmp = *dict;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
