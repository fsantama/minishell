/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:10:30 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/15 12:15:15 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	child(t_cmd *cmd, t_shell *shell)
{
	char	*error;

	error = NULL;
	if (!cmd->cmd)
	{
		ft_arrayfree(cmd->args);
		free(cmd->cmd);
		ft_putstr_fd(CMD_ERROR, 2);
	}
	if (execve(cmd->cmd, cmd->args, shell->envp) == -1)
	{
		error = ft_strjoinfree(cmd->cmd, ": ");
		error = ft_strjoinfree(error, CMD_ERROR);
		shell->exit = 127;
		ft_putstr_fd(error, 2);
	}
	exit (shell->exit);
}

static void	dup_assignation(t_shell *shell, t_cmd *cmd, int i)
{
	if (cmd->infile_redirect == 0)
	{
		dup2(shell->fd_in, 0);
	}
	if (i != shell->n_cmd - 1)
	{
		if (pipe(shell->tube) == -1)
			ft_putstr_fd(PIPE_ERROR, 2);
		if (cmd->infile_redirect == 0)
			shell->fd_in = shell->tube[0];
		if (cmd->outfile_redirect == 0)
			shell->fd_out = shell->tube[1];
	}
	else if (cmd->outfile_redirect == 0)
		shell->fd_out = dup(shell->tmp_out);
	if (cmd->outfile_redirect == 0)
	{
		dup2(shell->fd_out, 1);
		close(shell->fd_out);
	}
}

static int	pipe_control(t_shell *shell, t_cmd *cmd, int i)
{
	pid_t	pid;
	int		to_wait;

	dup_assignation(shell, &cmd[i], i);
	if (cmd[i].infile_redirect != 0 || cmd[i].outfile_redirect != 0)
		if (!redir_check(shell, &cmd[i], i))
			return (0);
	if (builting(&cmd[i], shell))
		return (1);
	pid = fork();
	if (!pid)
		child(&cmd[i], shell);
	if (i == shell->n_cmd - 1)
	{
		waitpid(pid, &to_wait, 0);
		shell->exit = WEXITSTATUS(to_wait);
	}
	return (2);
}

void	child_generator(t_shell *shell, t_cmd *cmd)
{
	int		i;
	int		nb_controler;
	int		keyboard_fd;
	int		display_fd;

	keyboard_fd = dup(0);
	display_fd = dup(1);
	i = -1;
	while (++i < shell->n_cmd)
	{
		nb_controler = pipe_control(shell, cmd, i);
		if (nb_controler == 0)
			break ;
		else if (nb_controler == 1)
			continue ;
	}
	dup2(keyboard_fd, 0);
	close(keyboard_fd);
	dup2(display_fd, 1);
	close(display_fd);
	ft_free_cmds(cmd, shell);
}
