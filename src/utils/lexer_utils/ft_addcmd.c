/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:33:31 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 18:26:07 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_heredoc(t_cmd *cmd)
{
	int		tmp_fd;
	char	*input;

	tmp_fd = open(HEREDOC_FILE, O_TRUNC | O_CREAT | O_RDWR, 0644);
	input = readline("> ");
	while (input && ft_strncmp(input, cmd->infile, ft_strlen(cmd->infile) + 1))
	{
		write(tmp_fd, input, ft_strlen(input));
		write(tmp_fd, "\n", 1);
		input = readline("> ");
	}
	close(tmp_fd);
	free(cmd->infile);
	cmd->infile = ft_strdup(HEREDOC_FILE);
}

char	*ft_getname(char *cmd, int *j)
{
	int		i;
	int		start;
	char	*name;
	char	*aux;

	i = 0;
	name = 0;
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '<' && cmd[i] != '>')
	{
		start = i;
		if (findquotes(cmd, &i))
			aux = ft_substr(cmd, start + 1, (i - start) - 1);
		else
			aux = ft_substr(cmd, start, 1);
		name = ft_strjoinfree(name, aux);
		free(aux);
		i++;
	}
	*j += i - 1;
	return (name);
}
