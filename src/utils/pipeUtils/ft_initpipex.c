/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initpipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:35:25 by fsantama          #+#    #+#             */
/*   Updated: 2023/11/15 18:47:33 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_initpipex(t_pipe *pipex, char **argv, char **envp)
{
	(void) argv;
	pipex->envp = ft_arraydup(envp);
	pipex->path = ft_getpath(pipex->envp);
}
