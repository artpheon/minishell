#ifndef DICT_H
# define DICT_H

# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct s_dict
{
	void				*key;
	void				*val;
	struct s_dict		*next;
}	t_dict;

t_dict					*dict_newentry(void *key, void *value);
void					dict_addentry(t_dict **dict, t_dict *new);
int						dict_rmentry(t_dict **dict, void *key);
void					*dict_getval(t_dict **dict, void *key);
void					prnt_keyisval(t_dict *lst);
void					prnt_declx(t_dict *lst);
void					dict_print(t_dict **list, void (*format)(t_dict *));
int						dict_chval(t_dict **dict, void *key, void *newval);
int						dict_size(t_dict **dict);
bool					dict_isin(t_dict **dict, void *key);

#endif