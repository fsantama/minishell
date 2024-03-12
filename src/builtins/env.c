/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:17 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/05 16:39:18 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_env(t_cmd *cmd, t_pipe *pipex)
{
	int	i;

	i = 0;
	if (cmd->argc != 1)
        printf("MiniShell: env: Too many arguments\n");
	while ((pipex->envp)[i++])
		ft_putendl_fd((pipex->envp)[i], STDOUT_FILENO);
}