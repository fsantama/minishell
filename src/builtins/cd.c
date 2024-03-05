#include "../../inc/minishell.h"

void    ft_cd(t_cmd *cmd, t_pipe *pipex)
{
    char    *curr_path;
    char    *new_path;

    curr_path = getcwd(NULL, 0);
    new_path = ft_strdup(cmd_args[1]);
    if (!new_path)
        //Devolver la carpeta raiz
	else if (ft_strncmp(path, "-", 2) == 0)
		//otro
	if (chdir(new_path))
		printf("MiniShell: cd: %s: No such file or directory\n", cmd->args[1]);
    
}