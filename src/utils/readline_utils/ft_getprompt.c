/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:53:59 by fsantama          #+#    #+#             */
/*   Updated: 2024/02/16 11:34:23 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*ft_getprompt(char *str)
{
	char	*prompt;
	char	*p1;
	char	*p2;
	char	*p3;
	char	*p4;

	p1 = ft_strjoin(GREEN, "➜ ");
	if (!p1)
		return (NULL);
	p2 = ft_strjoin(p1, CYAN);
	if (!p2)
		return (NULL);
	p3 = ft_strjoin(p2, str);
	if (!p3)
		return (NULL);
	p4 = ft_strjoin(p3, " > ");
	if (!p4)
		return (NULL);
	prompt = ft_strjoin(p4, DEFAULT);
	if (!prompt)
		return (NULL);
	return (free(p1), free(p2), free(p3), free(p4), free(str), prompt);
}

