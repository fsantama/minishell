/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:19:10 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/15 12:05:51 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_typetoken	ft_redirectstatus(char c, t_cmd *cmd, t_typetoken status)
{
	if (c == '>')
	{
		cmd->outfile_redirect = 1;
		if (status == RED_OUT)
		{
			cmd->outfile_redirect = 2;
			status = RED_APPEND;
		}
		else
			status = RED_OUT;
	}
	else if (c == '<')
	{
		cmd->infile_redirect = 1;
		if (status == RED_IN)
			status = RED_HERE;
		else
			status = RED_IN;
	}
	return (status);
}

static void	ft_fillcmd(char *one_cmd, int *i, t_shell *shell, t_cmd *cmd)
{
	if (!cmd->cmd)
	{
		cmd->cmd = ft_getname(&one_cmd[*i], i);
		cmd->args = ft_addarray(ft_strdup(cmd->cmd), cmd->args);
		cmd->cmd = ft_getcmd(*shell, cmd->cmd);
	}
	else
	{
		cmd->args = ft_addarray(ft_getname(&one_cmd[*i], i), cmd->args);
	}
}

static void	ft_fillfile(char *one_cmd, int *i, t_cmd *cmd, t_typetoken redtype)
{
	if (redtype == RED_IN || redtype == RED_HERE)
	{
		if (cmd->infile && redtype == RED_IN)
			free(cmd->infile);
		cmd->infile = ft_getname(&one_cmd[*i], i);
		if (redtype == RED_HERE)
			ft_heredoc(cmd);
	}
	else if (redtype == RED_OUT || redtype == RED_APPEND)
	{
		if (!cmd->outfile)
			cmd->outfile = ft_getname(&one_cmd[*i], i);
		else
		{
			close(open(cmd->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644));
			free(cmd->outfile);
			cmd->outfile = ft_getname(&one_cmd[*i], i);
		}
	}
}

static void	ft_getdatas(t_cmd *cmd, char *one_cmd, t_shell *shell)
{
	int			i;
	t_typetoken	status;

	i = 0;
	status = WORD;
	while (one_cmd && one_cmd[i])
	{
		status = ft_redirectstatus(one_cmd[i], cmd, status);
		if (one_cmd[i] != ' ' && one_cmd[i] != '\t' && one_cmd[i] != '<'
			&& one_cmd[i] != '>')
		{
			if (status == WORD)
				ft_fillcmd(one_cmd, &i, shell, cmd);
			else
				ft_fillfile(one_cmd, &i, cmd, status);
			status = WORD;
		}
		i++;
	}
}

t_cmd	*ft_getinput(char *input, t_shell *shell)
{
	int		i;
	char	**split_pipe;
	t_cmd	*cmd;

//	printf("Entro");
	i = 0;
	split_pipe = ft_splitshell(input, '|');
	split_pipe = ft_cleanspaces(split_pipe);
	cmd = ft_calloc(sizeof(t_cmd), shell->n_cmd);
	while (i < shell->n_cmd)
	{
		cmd[i].infile_redirect = 0;
		cmd[i].outfile_redirect = 0;
		cmd[i].infile = NULL;
		cmd[i].outfile = NULL;
		cmd[i].args = NULL;
		cmd[i].cmd = NULL;
		ft_getdatas(&cmd[i], split_pipe[i], shell);
		i++;
	}
	ft_arrayfree(split_pipe);
	return (cmd);
}
