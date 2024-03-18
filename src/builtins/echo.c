/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:07 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 19:22:00 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_echo(t_cmd *cmd)
{
	int	i;

	i = 1;
	if (cmd->args[1] && ft_strncmp(cmd->args[1], "-n", 3) == 0)
		i++;
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i++], 1);
		if (cmd->args[i])
			ft_putstr_fd(" ", 1);
	}
	if (!(cmd->args[1] && ft_strncmp(cmd->args[1], "-n", 3) == 0))
		ft_putstr_fd("\n", 1);
}
