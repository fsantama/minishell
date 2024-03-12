/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:44:19 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/05 14:53:00 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	ft_checkclose(char *quotes)
{
	int	i;
	int	com;

	i = 0;
	while (quotes[i])
	{
		if (quotes[i] == '\'' || quotes[i] == '"')
		{
			com = quotes[i];
			findquotes(quotes, &i);
			if (quotes[i] != com)
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_checkquotes(char *input)
{
	char	**quotes;
	int		i;

	i = 0;
	quotes = ft_splitshell(input, ' ');
	while (quotes[i])
	{
		if (ft_strchr(quotes[i], '\'') || ft_strchr(quotes[i], '"'))
		{
			if (ft_checkclose(quotes[i]) == 0)
			{
				ft_putendl_fd("Syntax error: ' or \" must be closed", 2);
				ft_arrayfree(quotes);
				return (1);
			}
		}
		i++;
	}
	ft_arrayfree(quotes);
	return (0);
}
