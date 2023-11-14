/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:08:17 by fsantama          #+#    #+#             */
/*   Updated: 2023/11/14 18:26:58 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

void	loop(void)
{
	char	*input;

	while (1)
	{
		input = get_line();
		if (!input)
			ft_error(INVALID_INPUT);
		add_history(input);
		free(input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	atexit(leaks);
	printf("%s", HEADER);
	if (argc == 1)
	{
		ft_init_pipe(&pipex, argv, envp);
		loop();
	}
	else
		ft_error(INVALID_ARGS);
	return (0);
}
