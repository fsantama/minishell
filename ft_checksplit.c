/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:03:29 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 14:19:50 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	ft_checksplit(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			printf("Word %d: %s\n", i + 1, split[i]);
			i++;
		}
		printf("Total words: %d\n", i);
	}
	else
		printf("Failed to split input\n");
}
