/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:02:44 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/19 18:37:04 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---------------------------------LIBRARIES----------------------------------*/

# include "Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <libgen.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <readline/history.h>
# include <readline/readline.h>

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
# define CMD_ERROR "Command not found\n"
# define PIPE_ERROR "Pipe error\n"
# define HEREDOC_FILE "/tmp/__spedismaracatermicers__"

/*----------------------------------READLINE----------------------------------*/

# define LINE "minishell > "

/*---------------------------------STRUCTURES---------------------------------*/

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	char	*infile;
	int		infile_redirect;
	char	*outfile;
	int		outfile_redirect;
}	t_cmd;

typedef struct s_shell
{
	char	**envp;
	char	**path;
	char	*pwd;
	char	*input;
	int		exit;
	int		n_cmd;
	int		tube[2];
	int		tmp_in;
	int		tmp_out;
	int		fd_in;
	int		fd_out;
}	t_shell;

typedef enum s_typetoken
{
	WORD,
	RED_OUT,
	RED_IN,
	RED_APPEND,
	RED_HERE,
}	t_typetoken;

/*---------------------------------FUNCTIONS----------------------------------*/

							//* Builtins functions *//

// builtin_utils
int		find_env_pos(char *str, char **envp);
char	**delete_env_item(int pos, char **array);

int		builting(t_cmd *cmd, t_shell *shell);
void	ft_cd(t_cmd *cmd, t_shell *shell);
void	ft_echo(t_cmd *cmd);
void	ft_env(t_cmd *cmd, t_shell *shell);
void	ft_exit(t_cmd *cmd, t_shell *shell);
void	ft_export(t_cmd *cmd, t_shell *shell, int len);
void	ft_pwd(t_cmd *cmd);
void	ft_unset(t_cmd *cmd, t_shell *shell);

							//* Executor functions *//

//expand
char	*ft_get_exit_status(char *var, t_shell *shell);
char	*ft_getenv(char *var, t_shell *shell);
char	*ft_expandit(char *input, t_shell *shell, int expand);
void	child_generator(t_shell *shell, t_cmd *cmd);
void	sigint_handler(int sig);

							//* Lexer functions *//

t_cmd	*ft_getinput(char *input, t_shell *shell);

							//* Parser functions *//

void	ft_parserinput(char *input, t_shell *shell);

							//* Utils functions *//

// env_utils
char	*ft_findbasename(const char *path);
void	ft_findenv(t_shell *shell, char **envp);

//	executor_utils
int		redir_check(t_shell *shell, t_cmd *cmd, int i);

char	**ft_findpath(char **envp);
char	*ft_findpwd(char **envp);

// general_utils
char	**ft_addarray(char *str, char **array);
void	ft_error(char *error, int error_code);
void	ft_freecmds(t_cmd *cmd, t_shell *shell);
void	ft_initshell(t_shell *shell);

// void	ft_initshell(t_shell shell);
void	ft_printheader(char *str);
char	*ft_strjoinfree(char *s1, char const *s2);

//lexer_utils
char	*ft_getname(char *cmd, int *j);
char	*ft_getcmd(t_shell *shell, char *cmd);
void	ft_heredoc(t_cmd *cmd);

// manage_array_utils
char	**ft_arraydup(char **array);
void	ft_arrayfree(char **array);
int		ft_arraylen(char **array);

// parser_utils

int		findquotes(char *str, int *i);
int		ft_countpipe(char *input);
int		ft_checkquotes(char *input);
int		ft_checkpipe(char *input);
int		ft_checkredirect(char *input);
char	**ft_splitshell(char *str, char s);
char	**ft_cleanspaces(char **split);

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