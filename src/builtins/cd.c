/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:39 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/15 13:11:09 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void    ft_cd(t_cmd *cmd, t_shell *shell)
{
    (void) shell;
    char    *curr_path;
    char    *new_path;

    curr_path = getcwd(NULL, 0);
    new_path = ft_strdup(cmd->args[1]);
    if (!new_path)
        //Devolver la carpeta raiz
    if (ft_strncmp(new_path, "-", 2) == 0)
		//otro
	if (chdir(new_path))
		printf("MiniShell: cd: %s: No such file or directory\n", cmd->args[1]);
}
