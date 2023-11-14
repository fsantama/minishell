/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:13 by fsantama          #+#    #+#             */
/*   Updated: 2023/11/14 18:34:38 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---------------------------------LIBRARIES----------------------------------*/

# include "Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <libgen.h>
# include <signal.h>
# include <fcntl.h>

/*-----------------------------------HEADER-----------------------------------*/

# define HEADER "\n\
\033[36;1m 	 _           _               _          _ _ 	\n \
 	| |__   __ _| |__  _   _ ___| |__   ___| | |	\n \
 	|  _ \\ / _  |  _ \\| | | / __|  _ \\ / _ \\ | |	\n \
 	| |_) | (_| | |_) | |_| \\__ \\ | | |  __/ | |	\n \
 	|_.__/ \\__,_|_.__/ \\__, |___/_| |_|\\___|_|_|	\n \
 	                   |___/                    	\n \
																		\n \
\033[37;1m              Develop by cejimene && fsantama                  \n \
\n\033[0m"

/*-----------------------------------ERRORS-----------------------------------*/

# define INVALID_ARGS "Usage: ./minishell\n"
# define INVALID_INPUT "Closing shell\n"

/*---------------------------------STRUCTURES---------------------------------*/

typedef struct s_pipe
{
	char	**envp;
	char	**path;
}	t_pipe;

/*---------------------------------FUNCTIONS----------------------------------*/

						//* Error control functions *//

void	ft_error(char *error);

							//* Pipex functions *//

void	ft_init_pipe(t_pipe *pipex, char **argv, char **envp);

							//* Utils functions *//

char	**ft_arraydup(char **array);
char	*get_line(void);

/*-----------------------------------COLORS-----------------------------------*/

# define BOLD		"\033[1m"
# define BLACK		"\033[30;1m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"
# define YELLOW		"\033[33;1m"
# define BLUE		"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define CYAN		"\033[36;1m"
# define WHITE		"\033[37;1m"
# define DEFAULT	"\033[0m"

#endif