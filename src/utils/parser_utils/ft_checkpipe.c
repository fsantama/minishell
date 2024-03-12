/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:39 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/05 14:26:28 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	ft_consecutivepipes(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		findquotes(input, &i);
		if (input[i] == '|')
		{
			i++;
			findquotes(input, &i);
			while (input[i] && (input[i] == ' ' || input[i] == '\t'))
				i++;
			if (input[i] && input[i] == '|')
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_countpipe(char *input)
{
	int	i;
	int	npipe;

	i = 0;
	npipe = 0;
	while (input[i])
	{
		findquotes(input, &i);
		if (input[i] == '|')
			npipe++;
		i++;
	}
	return (npipe);
}

static int	ft_checkn_pipes(char *input, char **split_pi)
{
	if (ft_countpipe(input) >= ft_arraylen(split_pi) || input[0] == '|'
		|| ft_consecutivepipes(input) == 1)
	{
		ft_putendl_fd("Syntax error near unexpected token '|'", 2);
		return (1);
	}
	return (0);
}

int	ft_checkpipe(char *input)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_splitshell(input, '|');
	split = ft_cleanspaces(split);
	if (ft_checkn_pipes(input, split))
		return (1);
	ft_arrayfree(split);
	return (0);
}
