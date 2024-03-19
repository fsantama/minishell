/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:08:04 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/19 12:10:57 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/**
 * @brief			Prints an error message. 
 *					Displays additional details about last error using perror.
 *					Exits the program with a failure status.
 * 
 * @param	error	A pointer to the error message string.
 */
void	ft_error(char *error, int error_code)
{
	(void) error_code;
	return (perror(error), exit(EXIT_FAILURE));
}
