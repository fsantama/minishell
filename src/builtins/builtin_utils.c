#include "../../inc/minishell.h"

int	find_env_pos(char *str, char **envp)
{
	int		i;
    int     len;
	char	*aux;

	i = -1;
    len = ft_strlen(str);
	if (!str[0])
		return (-1);
	while (envp[++i])
	{
		aux = ft_strchr(envp[i], '=') + 1;
		if (len == (aux - envp[i] - 1))
			if (ft_strncmp(str, envp[i], len) == 0)
				return (i);
	}
	return (-1);
}

char	**delete_env_item(int pos, char **array)
{
	int		i;
	char	**new_array;

	i = -1;
	if (!array || pos < 0 || pos > ft_arraylen(array))
		return (array);
	new_array = ft_calloc(sizeof(char *), ft_arraylen(array));
	while (array[++i])
	{
		if (i >= pos)
			new_array[i] = ft_strdup(array[i + 1]);
		else
			new_array[i] = ft_strdup(array[i]);
	}
	ft_arrayfree(array);
	return (new_array);
}