/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:17:13 by ajurado-          #+#    #+#             */
/*   Updated: 2024/03/19 18:43:40 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	check_duplicated_env(t_cmd *cmd, t_shell *shell)
{
	int		i;
	int		len;
	int		pos;
	char	*str;

	i = 0;
	while (cmd->args[1][i] && cmd->args[1][i] != '=')
		i++;
	len = i;
	str = ft_substr(cmd->args[1], 0, len);
	pos = find_env_pos(str, shell->envp);
	if (pos >= 0)
		shell->envp = delete_env_item(pos, shell->envp);
	free(str);
}

static void	export_cases(t_cmd *cmd, t_shell *shell)
{
	if (!cmd->args[1])
		ft_env(cmd, shell);
	if (cmd->args[1])
		check_duplicated_env(cmd, shell);
}

void	ft_export(t_cmd *cmd, t_shell *shell, int len)
{
	int		pos;
	char	*str;

	export_cases(cmd, shell);
	if (cmd->args[1] && ft_strchr(cmd->args[1], '='))
	{
		if (cmd->args[1][0] && (!ft_isalpha(cmd->args[1][0])
		&& cmd->args[1][0] != '_'))
		{
			printf("export: not a valid identifier\n");
			return ;
		}
		while (cmd->args[1][len] && cmd->args[1][len] != '=')
			len++;
		str = ft_substr(cmd->args[1], 0, len);
		pos = find_env_pos(str, shell->envp);
		if (pos < 0)
			shell->envp = ft_addarray(ft_strdup(cmd->args[1]), shell->envp);
		else
		{
			shell->envp = delete_env_item(pos, shell->envp);
			shell->envp = ft_addarray(cmd->args[1], shell->envp);
		}
		free(str);
	}
}
