/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:08:17 by fsantama          #+#    #+#             */
/*   Updated: 2023/10/19 19:35:08 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_line(void)
{
	char	*input;

	while (1)
	{
		input = readline(CYAN "babyshell 👶 " DEFAULT);
		if (input == NULL)
			ft_error(INVALID_INPUT);
	}
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
	{
		get_line();
	}
	else
		ft_error(INVALID_ARGS);
	return (0);
}
