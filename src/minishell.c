/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:08:17 by fsantama          #+#    #+#             */
/*   Updated: 2023/10/17 20:01:24 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv)
{
	(void)	argv;

	if (argc == 1)
	{
		printf("minishell> ");
	}
	else
		error(INVALID_ARGS);
	return (0);
}
