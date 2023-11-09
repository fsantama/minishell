/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:08:17 by fsantama          #+#    #+#             */
/*   Updated: 2023/11/09 19:40:15 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

char	*get_line(void)
{
	char	*input;

	input = readline(CYAN "babyshell 👶 " DEFAULT);
	if (input == NULL)
		ft_error(INVALID_INPUT);
	return (input);
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	pipex;

	(void) argv;
	atexit(leaks);
	printf("%s", HEADER);
	if (argc == 1)
	{
		ft_init_pipe(&pipex, argv, env);
		get_line();
	}
	else
		ft_error(INVALID_ARGS);
	return (0);
}
