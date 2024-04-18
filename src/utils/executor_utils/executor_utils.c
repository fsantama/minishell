/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:09:23 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/15 12:10:49 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	open_and_redir(t_shell *shell, t_cmd *cmd, int i)
{
	char	*error;

	error = NULL;
	shell->fd_in = open(cmd->infile, O_RDONLY);
	if (shell->fd_in == -1)
	{
		error = ft_strjoin(cmd->infile, ": No such file or directory\n");
		ft_putstr_fd(error, 2);
		free(error);
		return (0);
	}
	dup2(shell->fd_in, 0);
	if (i != shell->n_cmd - 1)
		shell->fd_in = shell->tube[0];
	return (1);
}

int	redir_check(t_shell *shell, t_cmd *cmd, int i)
{
	if (cmd->infile_redirect == 1)
		if (open_and_redir(shell, cmd, i) == 0)
			return (0);
	if (cmd->outfile_redirect == 0)
		return (1);
	if (cmd->outfile_redirect == 1)
		shell->fd_out = open(cmd->outfile, O_TRUNC | O_CREAT | O_RDWR, 0644);
	else if (cmd->outfile_redirect == 2)
		shell->fd_out = open(cmd->outfile, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (shell->fd_out == -1)
		return (0);
	dup2(shell->fd_out, 1);
	close(shell->fd_out);
	return (1);
}
