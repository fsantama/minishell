#include "../../../inc/minishell.h"

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