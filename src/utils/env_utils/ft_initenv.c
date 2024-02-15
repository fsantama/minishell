/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:36 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/15 17:42:31 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_initenv(t_shell *shell, char **envp)
{
	shell->envp = ft_arraydup(envp);
	shell->pwd = ft_findpwd(shell->envp);
	shell->old_pwd = ft_findoldpwd(shell->envp);
}
