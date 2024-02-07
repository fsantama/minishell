/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:16 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/07 16:43:37 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/**
 * @brief Prints the elements of a string array.
 * 
 * This function takes a string array as input and prints each element
 * of the array to the standard output. If the array is NULL, it prints
 * a message indicating that the array is NULL.
 * 
 * @param arr The string array to be printed.
 */
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
