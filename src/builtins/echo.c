/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:07 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 12:36:49 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static bool	has_n_flag(char *flag)
{
	int		i;

	i = 1;
	if (ft_strncmp(flag, "-n", 2) != 0)
		return (false);
	while (flag[i] && flag[i] == 'n')
		i++;
	return (!flag[i]);
}

static void	print_str(char **args, int idx)
{
	while (args[idx])
	{
		ft_putstr_fd(args[idx], STDOUT_FILENO);
		if (args[idx + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		idx++;
	}
}

void	ft_echo(t_cmd *cmd)
{
	if (cmd->argc == 2 && has_n_flag(cmd->args[1]))
		return ;
	else if (cmd->argc == 1)
		ft_putendl_fd("", STDOUT_FILENO);
	else if (cmd->argc >= 2 && !has_n_flag(cmd->args[1]))
	{
		print_str(cmd->args, 1);
		ft_putendl_fd("", STDOUT_FILENO);
	}
	else
		print_str(cmd->args, 2);
}
