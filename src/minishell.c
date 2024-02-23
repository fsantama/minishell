/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:40 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/23 13:00:48 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

void	loop(t_shell *shell)
{
	char	*tmp;
//	char **words;
char **split;


	while (1)
	{
		tmp = ft_getline(ft_getprompt(ft_findbasename(shell->pwd)));
		if (!tmp)
			ft_error(INVALID_INPUT, EPERM);
		else
		{
			add_history(tmp);
			shell->input = ft_strtrim(tmp, " ");
			split = ft_splitshell(shell->input, '|');
			ft_arrayprint(split);
/*words = ft_splitshell(shell->input, '|');
if (words) {
    int count = 0;
    while (words[count]) {
        printf("Word %d: %s\n", count + 1, words[count]);
        count++;
    }
    printf("Total words: %d\n", count);
} else {
    printf("Failed to split input\n");
}
*/
		}
		free (tmp);
		free(shell->input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	atexit(leaks);
	if (argc == 1 && argv[0])
	{
		ft_printheader(HEADER);
		ft_findenv(&shell, envp);
		// ft_initshell(&shell); aquí iniciaremos las variables como las señales 
		// y todo lo que necesitemos
		loop(&shell);
	}
	else
		ft_error(INVALID_ARGS, EPERM);
	return (0);
}
