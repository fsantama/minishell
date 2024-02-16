/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:05:39 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/16 11:51:34 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/**
 * @brief			Extracts the value of the "PWD" environment variable.
 * 
 * @param	envp	The array of environment variables.
 * @return	char*	A pointer to the value of the "PWD" environment variable.
 * 
 * NOTE:			Memory is allocated for the returned string.
 */
char	*ft_findpwd(char **envp)
{
	int		i;
	char	*pwd;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PWD=", 4))
			pwd = ft_substr(envp[i],
					4, ft_strlen(envp[i]) - 4);
		i++;
	}
	return (pwd);
}
