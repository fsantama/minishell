/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:05:13 by fsantama          #+#    #+#             */
/*   Updated: 2023/10/18 19:06:38 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---------------------------------LIBRARIES----------------------------------*/

//# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <libgen.h>
# include <signal.h>
# include <fcntl.h>

/*-----------------------------------HEADER-----------------------------------*/



/*-----------------------------------ERRORS-----------------------------------*/

#define INVALID_ARGS "Usage: ./minishell"

void	ft_error(char *error);

#endif