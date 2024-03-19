/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:16:37 by ajurado-          #+#    #+#             */
/*   Updated: 2024/03/19 10:00:16 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	find_env_pos(char *str, char **envp)
{
	int		i;
	int		len;
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
	int		arraylen;

	i = -1;
	arraylen = ft_arraylen(array);
	if (!array || pos < 0 || pos > arraylen)
		return (array);
	new_array = ft_calloc(sizeof(char *), arraylen);
	while (++i < pos && array[i])
		new_array[i] = ft_strdup(array[i]);
	while (++i < arraylen && array[i + 1])
		new_array[i - 1] = ft_strdup(array[i]);
	ft_arrayfree(array);
	return (new_array);
}
