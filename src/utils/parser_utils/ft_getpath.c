/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:30 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/16 11:55:09 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/**
 * @brief 			Retrieves the PATH variable from the environment variables.
 *
 * This function searches for the PATH variable in the given environment 
 * variables array and returns an array of strings representing the individual 
 * paths.
 *
 * @param 	envp 	The array of environment variables.
 * @return 			char** An array of strings representing the paths in the 
 * 					PATH variable.
 *               	Returns NULL if PATH is not found or is empty.
 */
char	**ft_getpath(char **envp)
{
	char	**path;
	size_t	i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (i == ft_arraylen(envp))
		path = 0;
	else
		path = ft_split(envp[i] + 5, ':');
	return (path);
}