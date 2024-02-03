#include "../../../inc/minishell.h"

void	ft_printarray(char **arr)
{
	if (arr == NULL)
	{
		printf("Array is NULL\n");
	}
	for (int i = 0; arr[i] != NULL; i++)
	{
		printf("%s\n", arr[i]);
	}
}