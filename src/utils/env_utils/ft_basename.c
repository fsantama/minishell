/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:12:17 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/16 11:51:42 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/**
 * @brief 			Extracts the base name from a given path string.
 * 
 * @param	path	The path string from which to extract the base name.
 * @return	char*	A pointer to the base name string.
 * 
 * NOTE: 			Memory is allocated for the returned string.
 */

char	*ft_basename(const char *path)
{
	const char	*basename;

	basename = ft_strrchr(path, '/');
	if (basename == NULL)
		return (ft_strdup(path));
	return (ft_strdup(basename + 1));
}
