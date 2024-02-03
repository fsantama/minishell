#include "../../../inc/minishell.h"

/**
 *	@brief			Frees the memory allocated for an array of strings.
 * 
 *	@param	array	A pointer to the array of strings to free.
 */
void	ft_arrayfree(char **array)
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