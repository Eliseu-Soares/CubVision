/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:41:01 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/28 19:45:14 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

int	get_height_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

bool	found_x_char(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'X')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

bool	is_invalid_space(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == ' ')
			{
				flood_fill_space(get_height_map(map), map, x, y);
				if (found_x_char(map))
					return (print_error(INVALID_MAP), true);
			}
			x++;
		}
		y++;
	}
	return (false);
}
