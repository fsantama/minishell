/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parserinput.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:24:01 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 18:28:12 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_existcmd(t_cmd *cmd, t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->n_cmd)
	{
		if (!cmd[i].cmd)
		{
			ft_putstr_fd("Command not found\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parsersyntax(char *input, t_shell *shell)
{
	if (ft_checkquotes(input) == 0 && ft_checkpipe(input) == 0
		&& ft_checkredirect(input) == 0)
		return (0);
	else
		return (shell->exit = 33, 1);
}

static char	*ft_waitpipe(char *input, t_shell *shell, char **split_pipe)
{
	char	*aux;

	aux = NULL;
	if (ft_countpipe(input) + 1 != shell->n_cmd)
	{
		while (ft_countpipe(input) + 1 != shell->n_cmd)
		{
			aux = readline("> ");
//			printf("entro");
//			printf("Numero de comandos: %d", shell->n_cmd);
			input = ft_strjoinfree(input, aux);
			free (aux);
			ft_arrayfree(split_pipe);
			if (parsersyntax(input, shell) == 1)
				return (input);
			split_pipe= ft_splitshell(input, '|');
			split_pipe = ft_cleanspaces(split_pipe);
			shell->n_cmd = ft_arraylen(split_pipe);
			ft_arrayfree(split_pipe); // Puede dar problemas en el futuro
		}
	}
	else
		ft_arrayfree(split_pipe);
	return (input);
}


void	ft_parserinput(char *input, t_shell *shell)
{
	char	**split_pipe;
	char	*new_input;
	t_cmd	*cmd;

//	split_pipe = NULL;
	new_input = NULL;
	if (parsersyntax(input, shell) == 0)
	{
		split_pipe = ft_splitshell(input, '|');
		split_pipe = ft_cleanspaces(split_pipe);
		shell->n_cmd = ft_arraylen(split_pipe);
		input = ft_waitpipe(input, shell, split_pipe);
		new_input = ft_expandit(input, shell, 0);
		cmd = ft_getinput(new_input, shell);
		free(new_input);
		// free (input);
//		ft_arrayfree(split_pipe);
		if (ft_existcmd(cmd, shell) == 1)
			child_generator(shell, cmd);
	}
	else
		shell->exit = 258;
}
