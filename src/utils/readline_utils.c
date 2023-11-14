/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:05:46 by fsantama          #+#    #+#             */
/*   Updated: 2023/11/14 18:45:53 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 *	@brief	Obtains a line of input from the user using the readline library.
 *			Displays a CYAN-colored prompt indicating it's a babyshell.
 * 
 *	@return	char* A pointer to the string entered by the user.
 
 *	NOTE:	The memory allocated for the string should be freed by the caller.
 */
char	*get_line(void)
{
	return (readline(CYAN "babyshell 👶 " DEFAULT));
}
