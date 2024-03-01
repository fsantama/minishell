#include "../../inc/minishell.h"

void	ft_env(t_cmd *cmd, t_pipe *pipex)
{
	int	i;

	i = 0;
	if (cmd->argc != 1)
        printf("MiniShell: env: Too many arguments\n");
	while ((pipex->envp)[i++])
		ft_putendl_fd((pipex->envp)[i], STDOUT_FILENO);
}