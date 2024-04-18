/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:46:58 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/14 12:49:17 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	**ft_addarray(char *str, char **array)
{
	char	**new_array;
	int		i;

	if (!array)
	{
		array = ft_calloc(sizeof(char *), 2);
		array[0] = str;
		return (array);
	}
	else
	{
		new_array = ft_calloc(sizeof(char *), ft_arraylen(array) + 2);
		i = -1;
		while (array[++i])
			new_array[i] = ft_strdup(array[i]);
		new_array[i] = ft_strdup(str);
		ft_arrayfree(array);
		free(str);
		return (new_array);
	}
}
