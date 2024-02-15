/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:05:39 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/15 17:42:52 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

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
