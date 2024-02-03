#include "../inc/minishell.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

void	loop(t_pipe *pipex)
{
	char	*input;
	char	*aux;
	(void) pipex;
	while (1)
	{
		input = ft_getline(LINE);
		if (!input)
			ft_error(INVALID_INPUT);
		add_history(input);
		aux = ft_strtrim(input, " ");
//		if (ft_strlen(input) > 0 && ft_strlen(aux) > 0)
//			printf("hola");
//		else
			free(input);
		free (aux);
//		ft_arrayfree(pipex->path);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	atexit(leaks);
	printf("%s", HEADER);
	if (argc == 1)
	{
		ft_initpipex(&pipex, argv, envp);
//		ft_printarray(pipex.path);
//		ft_printarray(pipex.envp);
		loop(&pipex);
	}
	else
		ft_error(INVALID_ARGS);
	return (0);
}