/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:39 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/19 16:24:24 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_cd(t_cmd *cmd, t_shell *shell)
{
	char	*curr_path;
	char	*new_path;
	char	*aux;

	new_path = NULL;
	curr_path = getcwd(NULL, 0);
	if (cmd->args[1])
		new_path = ft_strdup(cmd->args[1]);
	if (!new_path)
		new_path = ft_getenv("HOME", shell);
	if (chdir(new_path))
		printf("cd: %s: No such file or directory\n", cmd->args[1]);
	else
	{
		shell->envp = delete_env_item(\
		find_env_pos("OLDPWD", shell->envp), shell->envp);
		aux = ft_strjoin("OLDPWD=", curr_path);
		free(curr_path);
		shell->envp = ft_addarray(aux, shell->envp);
	}
	free(new_path);
}
