/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:32:22 by elsoares          #+#    #+#             */
/*   Updated: 2026/05/09 13:17:52 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

char	**new_map(char **lines, int j)
{
	int		weight;
	int		height;
	int		i;
	char	**new_map;

	new_map = NULL;
	i = 0;
	weight = (get_max_line(lines) + 2);
	height = j + 2;
	new_map = ft_calloc(sizeof(char *), (height + 2));
	while (i <= height)
	{
		new_map[i] = ft_calloc(weight + 1, sizeof(char));
		new_map[i] = ft_memset(new_map[i], '-', weight);
		i++;
	}
	return (new_map);
}

char	**fill_new_map(char **lines, int j)
{
	char	**map;
	int		x;
	int		y;
	int		i;

	x = 1;
	(void)y;
	(void)i;
	(void)x;
	i = 0;
	map = NULL;
	map = new_map(lines, j);
	while (map[x] && lines[i])
	{
		if (lines[i])
			hz_strcpy(map[x], lines[i], 1);
		i++;
		x++;
	}
	return (map);
}

bool	check_char_invalid_in_map(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr("10NSWE", map[y][x]) && !ft_isspace(map[y][x]))
				return (print_error(INVALID_CHARACTER), true);
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
				|| map[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count > 1)
		return (print_error(MULTIPLE_PLAYER), true);
	if (count == 0)
		return (print_error(NO_PLAYER), true);
	return (false);
}

bool	is_map_invalid(char **new_map)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (new_map[y])
	{
		x = 0;
		while (new_map[y][x])
		{
			if (new_map[y][x] == 'X')
				return (print_error(INVALID_MAP), true);
			x++;
		}
		y++;
	}
	while (new_map[i])
	{
		free(new_map[i]);
		i++;
	}
	free(new_map);
	return (false);
}

bool	flood_fill_space(int height, char **map, int x, int y)
{
	int	width;

	width = get_max_line(map);
	if (x < 0 || y < 0 || x >= width || y >= height)
		return (true);
	if (!map[y] || x >= (int)ft_strlen(map[y]))
		return (true);
	if (map[y][x] == '1' || map[y][x] == 'v')
		return (true);
	if (ft_strchr("0NSWE", map[y][x]))
	{
		map[y][x] = 'X';
		return (false);
	}
	map[y][x] = 'v';
	flood_fill_space(height, map, x + 1, y);
	flood_fill_space(height, map, x - 1, y);
	flood_fill_space(height, map, x, y + 1);
	flood_fill_space(height, map, x, y - 1);
	flood_fill_space(height, map, x + 1, y - 1);
	flood_fill_space(height, map, x + 1, y + 1);
	flood_fill_space(height, map, x - 1, y + 1);
	flood_fill_space(height, map, x - 1, y - 1);
	return (true);
}
