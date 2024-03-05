/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parserinput.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:24:01 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/20 17:53:25 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	parsersyntax(t_shell *shell)
{
	if (ft_checkquotes(shell) && ft_checkpipe(shell) && ft_checkredirect(shell))
		return (0);
	else
		return (1);
}

void	ft_parserinput(t_shell *shell)
{
	if (parsersyntax(shell) == 0)
	{
		write(1, "entra", 5);
		//sigo con la lógica de parseo
	}
	else
		write(1, "no entra", 8);
		// poner el error aquí
}

