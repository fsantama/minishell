/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:40 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 19:07:55 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

void	loop(t_shell *shell)
{
	char	*tmp;

	while (1)
	{
		tmp = ft_getline(ft_getprompt(ft_findbasename(shell->pwd)));
		if (!tmp)
			ft_error(INVALID_INPUT, EPERM);
		add_history(tmp);
		shell->input = ft_strtrim(tmp, " ");
		ft_parserinput(shell->input, shell);
		free (tmp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	atexit(leaks);
	if (argc == 1 && argv[0])
	{
		ft_printheader(HEADER);
		ft_findenv(&shell, envp);
		ft_initshell(&shell);
		loop(&shell);
	}
	else
		ft_error(INVALID_ARGS, EPERM);
	return (0);
}
