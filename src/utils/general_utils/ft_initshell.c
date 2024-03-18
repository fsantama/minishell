/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:36:38 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 16:49:05 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_initshell(t_shell *shell)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	shell->fd_in = dup(0);
	shell->tmp_out = dup(1);
}
