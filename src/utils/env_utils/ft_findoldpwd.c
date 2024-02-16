/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findoldpwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:42:23 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/16 11:51:37 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/**
 * @brief 			Extracts the value of the "OLDPWD" environment variable.
 * 
 * @param	envp	The array of environment variables.
 * @return	char*	A pointer to the value of the "OLDPWD" environment variable.
 * 
 * NOTE: 			Memory is allocated for the returned string.
 */
char	*ft_findoldpwd(char **envp)
{
	int		i;
	char	*old_pwd;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "OLDPWD=", 7))
			old_pwd = ft_substr(envp[i],
					7, ft_strlen(envp[i]) - 7);
		i++;
	}
	return (old_pwd);
}
