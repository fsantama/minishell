/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:32:59 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/19 12:21:01 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char	*join;
	size_t	size;
	int		i;

	if (!s1 && !s2)
		return (0);
	size = 0;
	if (s1)
		size += ft_strlen(s1);
	size += ft_strlen(s2);
	join = (char *) malloc(sizeof (char) * (size + 1));
	if (!join)
		return (0);
	i = 0;
	if (s1)
		i = ft_strlen(s1);
	ft_memcpy(join, s1, i);
	ft_memcpy(&join[i], s2, ft_strlen(s2));
	join[size] = 0;
	free(s1);
	return (join);
}
