/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:50:19 by elsoares          #+#    #+#             */
/*   Updated: 2026/05/09 14:19:58 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

bool	is_empty_line(char *line)
{
	if (line[0] == '\0' || line[0] == '\n')
		return (true);
	return (false);
}

bool	is_invalid_map(char **map)
{
	int		i;
	bool	empty_line;
	bool	valid_line;

	i = 0;
	empty_line = false;
	valid_line = false;
	while (map[i])
	{
		if (is_empty_line(map[i]))
		{
			if (valid_line)
				empty_line = true;
		}
		else
		{
			valid_line = true;
			if (empty_line)
				return (print_error(INVALID_MAP), true);
		}
		i++;
	}
	return (false);
}
