/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:17 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/19 10:41:36 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_env(t_cmd *cmd, t_shell *shell)
{
	int	i;

	i = -1;
	if (cmd->args[1])
		printf("env: %s: No such file or directory\n", cmd->args[1]);
	else
	{
		while ((shell->envp)[++i])
			ft_putendl_fd((shell->envp)[i], STDOUT_FILENO);
	}
}
