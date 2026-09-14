/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_with_space_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:21:00 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/22 19:21:53 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

bool	strncmp_with_spaces(char *raw_path, char *indetifier)
{
	char	*with_space;
	int		len;

	len = 0;
	with_space = NULL;
	with_space = ft_strjoin(indetifier, " ");
	len = ft_strlen(with_space);
	if (ft_strncmp(raw_path, with_space, len) == 0)
	{
		if (with_space)
			free(with_space);
		return (true);
	}
	if (with_space)
		free(with_space);
	with_space = ft_strjoin(indetifier, "\t");
	if (ft_strncmp(raw_path, with_space, len) == 0)
	{
		if (with_space)
			free(with_space);
		return (true);
	}
	if (with_space)
		free(with_space);
	return (false);
}
