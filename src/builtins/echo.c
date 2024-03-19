/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:07 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/19 10:23:22 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static bool	check_flag(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (false);
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

void	ft_echo(t_cmd *cmd)
{
	int	i;

	i = 1;
	if (cmd->args[1] && check_flag(cmd->args[1]))
		i++;
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i++], 1);
		if (cmd->args[i])
			ft_putstr_fd(" ", 1);
	}
	if (!(cmd->args[1] && check_flag(cmd->args[1])))
		ft_putstr_fd("\n", 1);
}
