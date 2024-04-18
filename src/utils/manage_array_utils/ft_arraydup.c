/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:08 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/16 11:52:40 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/**
 *	@brief Duplicates an array of strings.
 * 
 *	@param	array	A pointer to the array of strings to duplicate.
 *	@return 		char** A pointer to a new array (duplicated strings).
 *	
 *	NOTE: 			The memory allocated for the new array and strings should be 
 *					freed by the caller.
 */
char	**ft_arraydup(char **array)
{
	char	**copy_array;
	size_t	i;

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
