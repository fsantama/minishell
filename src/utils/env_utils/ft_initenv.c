/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initpipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:36 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/08 11:23:43 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_initenv(t_shell *shell, char **argv, char **envp)
{
	(void) argv;
	shell->envp = ft_arraydup(envp);
	shell->path = ft_getpath(shell->envp);
}
