/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:02:44 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/05 11:25:32 by fsantama         ###   ########.fr       */
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
\033[36;1m		    _       _     _          _ _ \n \
 	  _ __ ___ (_)_ __ (_)___| |__   ___| | |\n \
 	 | '_ ` _  | | '_  | / __| '_  |/ _ | | |\n \
 	 | | | | | | | | | | |__ | | | |  __/ | |\n \
 	 |_| |_| |_|_|_| |_|_|___/_| |_||___|_|_|\n \
																		\n \
\033[37;1m            Develop by ajurado- && fsantama                  \n \
\n\033[0m"

/*-----------------------------------ERRORS-----------------------------------*/

# define INVALID_ARGS "Usage: ./minishell\n"
# define INVALID_INPUT "Closing shell\n"

/*-----------------------------------ERRORS-----------------------------------*/

# define LINE "minishell > "

/*---------------------------------STRUCTURES---------------------------------*/

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
}	t_cmd;

typedef struct s_pipe
{
	char	**envp;
	char	**path;
	int		fd_in;
	int		fd_out;
	int		tmp_in;
	int		tmp_out;
}	t_pipe;

/*---------------------------------FUNCTIONS----------------------------------*/

						//* Error control functions *//

void	ft_error(char *error);

							//* Pipex functions *//

							//* Utils functions *//

// manageArrayUtils

char	**ft_arraydup(char **array);
void	ft_arrayfree(char **array);
size_t	ft_arraylen(char **array);
void	ft_printarray(char **array);

// parserUtils

char	**ft_getpath(char **envp);

// pipeUtils

void	ft_initpipex(t_pipe *pipex, char **argv, char **envp);

// readlineUtils

char	*ft_getline(char *str);

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