/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:17:05 by ajurado-          #+#    #+#             */
/*   Updated: 2024/03/18 14:17:43 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_checkexit(t_cmd *cmd)
{
	int	i;

	i = -1;
	if (cmd->args[1])
	{
		while (cmd->args[1][++i])
		{
			if (!ft_isdigit(cmd->args[1][i]))
			{
				printf("exit: Numeric argument required");
				ft_putendl_fd(cmd->args[1], 2);
				return (-1);
			}
		}
		return (ft_atoi(cmd->args[1]));
	}
	return (0);
}

void	ft_exit(t_cmd *cmd, t_shell *shell)
{
	shell->exit = ft_checkexit(cmd);
	if (cmd->args[1] && cmd->args[2])
		printf("exit: Too many arguments");
	else if (shell->exit != -1)
	{
		ft_arrayfree(shell->envp);
		ft_arrayfree(shell->path);
		ft_freecmds(cmd, shell);
		exit(shell->exit);
	}
}
