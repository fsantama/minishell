/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:02:44 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/20 17:12:48 by fsantama         ###   ########.fr       */
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
# include <errno.h>

/*-----------------------------------HEADER-----------------------------------*/

# define HEADER "\n\
\033[36;1m		    _       _     _          _ _ \n \
 	  _ __ ___ (_)_ __ (_)___| |__   ___| | |\n \
 	 |  _   _  | |  _  | / __|  _  |/ _ | | |\n \
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

typedef struct s_shell
{
	char	**envp;
	char	**path;
	char	*pwd;
	char	*old_pwd;
	char 	*input;
	t_cmd	*cmd;
}	t_shell;

/*---------------------------------FUNCTIONS----------------------------------*/

							//* Builtins functions *//

//void    ft_pwd(void);

							//* Parser functions *//

void	ft_parserinput(t_shell *shell);
							
							//* Utils functions *//

// env_utils
char	*ft_findbasename(const char *path);
void	ft_findenv(t_shell *shell, char **envp);
char	*ft_findoldpwd(char **envp);
char	**ft_findpath(char **envp);
char	*ft_findpwd(char **envp);

// general_utils
void	ft_error(char *error, int error_code);
// void	ft_initshell(t_shell shell);
void	ft_printheader(char *str);

// manage_array_utils
char	**ft_arraydup(char **array);
void	ft_arrayfree(char **array);
size_t	ft_arraylen(char **array);
void	ft_arrayprint(char **array);

// parser_utils


// readline_utils
char	*ft_getline(char *str);
char	*ft_getprompt(char *str);

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