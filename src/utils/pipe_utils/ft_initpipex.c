#include "../../../inc/minishell.h"

void	ft_initpipex(t_pipe *pipex, char **argv, char **envp)
{
	(void) argv;
	pipex->envp = ft_arraydup(envp);
	pipex->path = ft_getpath(pipex->envp);
}