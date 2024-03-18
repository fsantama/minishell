/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkredirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:46:33 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 14:19:32 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static void	ft_scapespaces(char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		*i += 1;
}

/**
 * @brief Localiza en un string el simbolo '<' o '>' que no esté entre
 * comillas. 
 * 
 * @param input string en el que buscar 
 * @return int 0 si no existe ninguno, 1 si existe > y 2 si existe <
 */
int	ft_existred(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		findquotes(input, &i);
		if (input[i] && input[i] == '>')
			return (1);
		else if (input[i] && input[i] == '<')
			return (2);
		i++;
	}
	return (0);
}

/**
 * @brief Localiza simbolos de redirección consecutivos separados por espacios
 * 
 * @param cmd string en el que buscar
 * @param symbol tipo de simbolo que localizar '<' o '>'
 * @return int 0 si no están consecutivos 1 si lo están
 */
static int	ft_checksymbols(char *cmd, int symbol)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == symbol)
		{
			while (cmd[i] == '<' || cmd[i] == '>')
				i++;
			ft_scapespaces(cmd, &i);
			if (cmd[i] && (cmd[i] == '<' || cmd[i] == '>'))
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Verifica si la sintaxis de redirecciones en un comando es correcta, 
 * devuelve error en el caso de '<<<' o '>>>' o '><'
 * 
 * @param cmd string a verificar
 * @return int 0 si todo está correcto, 1 si hay error de sintaxis
 */
static int	ft_sintaxred(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		findquotes(cmd, &i);
		if (cmd[i] == '>')
		{
			if (ft_strncmp(&cmd[i], "><", 2) == 0 || cmd[i + 1] == 0
				|| ft_strncmp(&cmd[i], ">>>", 3) == 0)
				return (1);
		}
		else if (cmd[i] == '<')
		{
			if (ft_strncmp(&cmd[i], "<<<", 3) == 0 || cmd[i + 1] == 0)
				return (1);
		}
	}
	return (0);
}

/**
 * @brief En un string verifica si la sintaxis de redirección es correcta, 
 * comprueba que exista redirección (sin estar entre comillada) y en tal caso
 * verifica si la sintaxis es correcta.
 * 
 * @param input string que verificar
 * @return int 1 si hay error, 0 si todo es correcto
 */
int	ft_checkredirect(char *input)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_splitshell(input, '|');
	split = ft_cleanspaces(split);
	while (split[i] != 0)
	{
		if (ft_existred(split[i])
			&& (ft_sintaxred(split[i]) == 1
				|| ft_checksymbols(split[i], '>') == 1
				|| ft_checksymbols(split[i], '<') == 1))
		{
			ft_putendl_fd("Syntax error near unexpected token `>'", 2);
			return (1);
		}
		i++;
	}
	ft_arrayfree(split);
	return (0);
}
