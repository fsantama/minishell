/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:40 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 14:12:20 by ajurado-         ###   ########.fr       */
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
//		ft_checksplit(ft_splitshell(shell->input, '|'));
		ft_parserinput(shell->input, shell);
		free (tmp);
//		free(shell->input);
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
		// ft_initshell(&shell); aquí iniciaremos las variables como las señales 
		// y todo lo que necesitemos
		loop(&shell);
	}
	else
		ft_error(INVALID_ARGS, EPERM);
	return (0);
}
