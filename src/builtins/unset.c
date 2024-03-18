#include "../../inc/minishell.h"

void	ft_unset(t_cmd *cmd, t_shell *shell)
{
	int		pos;

	if (cmd->args[1])
	{
		pos = find_env_pos(cmd->args[1], shell->envp);
		if (pos >= 0)
			shell->envp = delete_env_item(pos, shell->envp);
	}
}