/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:40 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/16 11:28:40 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

void	loop(t_shell *shell)
{
	char	*input;
	char	*aux;
	(void) shell;

	while (1)
	{
		input = ft_getline(ft_getprompt(ft_basename(shell->pwd)));
		if (!input)
			ft_error(INVALID_INPUT, EPERM);
		add_history(input);
		aux = ft_strtrim(input, " ");
		free(input);
		free (aux);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	atexit(leaks);
	if (argc == 1 && argv[0])
	{
		ft_printheader(HEADER);
		ft_initenv(&shell, envp);
		loop(&shell);
	}
	else
		ft_error(INVALID_ARGS, EPERM);
	return (0);
}
