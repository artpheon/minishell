//
// Created by Howe Robbin on 4/8/21.
//

#include "dict.h"

t_dict	*dict_newentry(void *key, void *value)
{
	t_dict	*new;

	new = (t_dict *)malloc(sizeof(t_dict));
	if (new == NULL)
		return (NULL);
	new->key = key;
	new->val = value;
	new->next = NULL;
	return (new);
}

void	dict_addentry(t_dict **dict, t_dict *new)
{
	t_dict	*tmp;

	tmp = *dict;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

int	dict_rmentry(t_dict **dict, void *key)
{
	t_dict	*runner;
	t_dict	*tmp;

	runner = *dict;
	tmp = runner;
	while (runner)
	{
		if (ft_strcmp((char *)key, (char *)runner->key) == 0)
		{
			if (tmp == runner)
				*dict = runner->next;
			else
				tmp->next = runner->next;
			free(runner->key);
			free(runner->val);
			free(runner);
			return (1);
		}
		tmp = runner;
		runner = runner->next;
	}
	return (0);
}

void	*dict_getval(t_dict **dict, void *key)
{
	t_dict	*tmp;

	tmp = *dict;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp->val);
		tmp = tmp->next;
	}
	return (NULL);
}

bool	dict_isin(t_dict **dict, void *key)
{
	t_dict	*runner;

	runner = *dict;
	while (runner)
	{
		if (ft_strcmp((char *)key, (char *)runner->key) == 0)
			return (true);
		runner = runner->next;
	}
	return (false);
}
