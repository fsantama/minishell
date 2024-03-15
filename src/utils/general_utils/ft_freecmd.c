/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freecmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:23:41 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/15 13:04:23 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	free_cmd_structure(t_cmd *cmd)
{
	ft_arrayfree(cmd->args);
	free(cmd->cmd);
	free(cmd->infile);
	free(cmd->outfile);
}

void	ft_freecmds(t_cmd *cmd, t_shell *shell)
{
	int	i;

	i = 0;
	if (cmd)
	{
		while (i < shell->n_cmd)
		{
			free_cmd_structure(&cmd[i]);
			i++;
		}
		free(cmd);
		cmd = NULL;
	}
}
