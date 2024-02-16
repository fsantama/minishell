/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:12:17 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/15 18:21:00 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*ft_basename(const char *path)
{
	const char	*basename;

	basename = ft_strrchr(path, '/');
	if (basename == NULL)
		return (ft_strdup(path));
	return (ft_strdup(basename + 1));
}
