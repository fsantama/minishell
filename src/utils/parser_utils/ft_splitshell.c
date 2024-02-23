/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:33 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/23 12:26:48 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"
|
int	foundquotes(char *str, int *i)
{
	char	com;

	com = 0;
	if ((str[*i] == '\'' || str[*i] == '"') && str[*i] != '\0')
	{
		com = str[*i];
		(*i)++;
		while (str[*i] != '\0' && str[*i] != com)
			(*i)++;
		return (1);
	}
	return (0);
}

static int	countwords(char *str, char s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == s && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			n++;
			while (str[i] != '\0' && str[i] != s)
			{
				if (foundquotes(str, &i))
				{
				}
				else
				{
					i++;
				}
			}
		}
	}
	return (n);
}

char	**ft_splitshell(char *str, char s)
{
	int		i;
	int		is;
	int		len;
	char	**split;

	i = 0;
	is = 0;
	len = 0;
	split = ft_calloc(sizeof(char *), countwords(str, s) + 1);
	if (!split)
		return (NULL);
	while (str[i])
	{
		while (str[i] == s && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			len = i;
			while (str[i] != '\0' && str[i] != s)
			{
				if (foundquotes(str, &i))
					i++;
				else
					i++;
			}
			split[is++] = ft_substr(str, len, i - len);
			if (!split[is - 1])
			{
				ft_arrayfree(split);
				return (NULL);
			}
		}
	}
	return (split);
}
