#include "../../inc/minishell.h"

void	ft_export(t_cmd *cmd, t_shell *shell, int len)
{
	int		pos;
	char	*str;

	if (cmd->args[1] && ft_strchr(cmd->args[1], '='))
	{
		if (cmd->args[1][0] && (!ft_isalpha(cmd->args[1][0])
		&& cmd->args[1][0] != '_'))
		{
			err_msg("export: not a valid identifier\n");
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