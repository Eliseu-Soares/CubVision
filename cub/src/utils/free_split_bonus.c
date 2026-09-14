/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:22:02 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/22 19:23:02 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		i++;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}
