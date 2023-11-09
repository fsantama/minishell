/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:55:05 by fsantama          #+#    #+#             */
/*   Updated: 2023/11/09 19:39:17 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

size_t	ft_arraylen(char **array)
{
	size_t	i;

	i = 0;
	if (array == NULL)
		return (0);
	while (array[i])
		i++;
	return (i);
}

char	**ft_arraydup(char **array)
{
	char	**copy_array;
	int		i;

	i = 0;
	if (array == NULL)
		return (NULL);
	copy_array = ft_calloc(sizeof(char *), ft_arraylen(array) + 1);
	while (array[i])
	{
		copy_array[i] = ft_strdup(array[i]);
		i++;
	}
	return (copy_array);
}
