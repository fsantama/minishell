/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:35:25 by fsantama          #+#    #+#             */
/*   Updated: 2023/11/09 19:39:38 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init_pipe(t_pipe *pipex, char **argv, char **envp)
{
	(void) argv;
	pipex->envp = ft_arraydup(envp);
}
