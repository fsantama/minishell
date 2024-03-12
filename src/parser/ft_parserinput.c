/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parserinput.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:24:01 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/12 16:35:02 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	parsersyntax(char *input, t_shell *shell)
{
	(void) shell;
//	(void) input;
	if (ft_checkquotes(input) == 0 && ft_checkpipe(input) == 0
		&& ft_checkredirect(input) == 0)
		return (0);
	else
		return (1);
}

void	ft_parserinput(char *input, t_shell *shell)
{
	char	**split_pipe;
	
	if (parsersyntax(input, shell) == 0)
	{
		split_pipe = ft_splitshell(input, '|');
		split_pipe = ft_cleanspaces(split_pipe);
		// sigo con la lógica de parseo
	}
	else
		write(1, "no entra", 8);
	// poner el error aquí
}
