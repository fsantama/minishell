#include "../../inc/minishell.h"

int	builting(t_cmd *cmd, t_pipe *pipex)
{
    int	i;

	i = 0;
	while ((cmd->args[0])[i++])
		ft_tolower((cmd->args[0])[i]);
	if (!ft_strncmp(cmd->args[0], "echo", 5))
		ft_echo(cmd);
	else if (!ft_strncmp(cmd->args[0], "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(cmd->args[0], "cd", 3))
		ft_cd(cmd, pipex);
	else if (!ft_strncmp(cmd->args[0], "env", 4))
		ft_env(cmd, pipex);
	else if (!ft_strncmp(cmd->args[0], "exit", 5))
		ft_exit(cmd, pipex);
	else
		return (0);
	return (1);
}