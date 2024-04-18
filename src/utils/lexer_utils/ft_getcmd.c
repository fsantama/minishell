/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:51:49 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/19 18:40:32 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*ft_getcmd(t_shell *shell, char *cmd)
{
	int		i;
	char	*aux;
	char	*c;
	char	*ex;

	i = 0;
	while (cmd[i] != 0 && cmd[i] != ' ')
		i++;
	ex = ft_substr(cmd, 0, i);
	i = 0;
	if (access(ex, X_OK) == 0)
		return (free(cmd), ex);
	ft_arrayfree(shell->path);
	shell->path = ft_findpath(shell->envp);
	while (shell->path && shell->path[i])
	{
		aux = ft_strjoin(shell->path[i], "/");
		c = ft_strjoin(aux, ex);
		free (aux);
		if (access(c, X_OK) == 0)
			return (free (ex), free(cmd), c);
		free (c);
		i++;
	}
	return (free(ex), cmd);
}
