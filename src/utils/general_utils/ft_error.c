/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:08:04 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/05 10:17:20 by fsantama         ###   ########.fr       */
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
void	ft_error(char *error)
{
	return (ft_putstr_fd(error, 2), perror(""), exit(EXIT_FAILURE));
}