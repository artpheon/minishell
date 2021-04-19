#include "minishell.h"

bool	export_valcheck(char *str)
{
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (false);
	while (*str != '\0' && *str != '=')
	{
		if (!ft_isalnum(*str) && *str != '_' && *str != '+' && *str != '=')
			return (false);
		if (*str == '+' && *(str + 1) != '=')
			return (false);
		str++;
	}
	return (true);
}

char	**ft_split_2(char *str, char c)
{
	char	**arr;
	char	*word;
	int		sign;

	arr = malloc(sizeof(char *) * 3);
	if (arr == NULL)
		return (NULL);
	sign = 0;
	while (str[sign] != c)
		sign++;
	word = ft_substr(str, 0, sign);
	arr[0] = word;
	word = ft_substr(str, sign + 1, strlen(str));
	arr[1] = word;
	arr[2] = NULL;
	return (arr);
}
