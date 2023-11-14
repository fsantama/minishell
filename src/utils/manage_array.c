/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:55:05 by fsantama          #+#    #+#             */
/*   Updated: 2023/11/14 19:02:38 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 *	@brief			Frees the memory allocated for an array of strings.
 * 
 *	@param	array	A pointer to the array of strings to free.
 */
void	ft_free_array(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

/**
 *	@brief			Calculates the length of an array of strings.
 * 
 *	@param	array	A pointer to the array of strings.
 *	@return			size_t The number of strings in the array.
 */
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

/**
 *	@brief Duplicates an array of strings.
 * 
 *	@param	array	A pointer to the array of strings to duplicate.
 *	@return 		char** A pointer to a new array containing duplicated strings.
 *	NOTE: 			The memory allocated for the new array and strings should be 
 					freed by the caller.
 */
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
