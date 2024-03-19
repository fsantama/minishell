/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:34 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/19 10:44:36 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(t_cmd *cmd)
{
	char	*path;

	if (cmd->args[1])
	{
		ft_putendl_fd("pwd: too many arguments", 2);
		return ;
	}
	else
	{
		path = getcwd(NULL, 0);
		ft_putendl_fd(path, 1);
		free(path);
	}
}
