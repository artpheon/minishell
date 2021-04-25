#include "minishell.h"

void    args_to_low(t_cmd **cmds, int num)
{
    int i;

    i = 0;
    while(i < num && *cmds[i]->arg != NULL)
    {
        wtolow(cmds[i]->arg);
        ++i;
    }
}