/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:17 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 18:43:32 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_env(t_cmd *cmd, t_shell *shell)
{
	int	i;

	i = -1;
	if (cmd->argc != 1)
		printf("MiniShell: env: Too many arguments\n");
	while ((shell->envp)[++i])
		ft_putendl_fd((shell->envp)[i], STDOUT_FILENO);
}
