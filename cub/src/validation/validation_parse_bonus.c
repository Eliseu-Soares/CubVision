/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_parse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:27:17 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/28 19:51:51 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

bool	validate_texture(t_cubo *cubo)
{
	if (!cubo->maps->no || !cubo->maps->so)
		return (print_error(NOT_FOUND_TEXTURE), false);
	if (!cubo->maps->ea || !cubo->maps->we)
		return (print_error(NOT_FOUND_TEXTURE), false);
	if (!validation_extension(cubo->maps->no, ".xpm"))
		return (print_error(ERR_FILE_NOT_XPM), false);
	if (!validation_extension(cubo->maps->so, ".xpm"))
		return (print_error(ERR_FILE_NOT_XPM), false);
	if (!validation_extension(cubo->maps->ea, ".xpm"))
		return (print_error(ERR_FILE_NOT_XPM), false);
	if (!validation_extension(cubo->maps->we, ".xpm"))
		return (print_error(ERR_FILE_NOT_XPM), false);
	if (!is_empty_file_and_valid_file(cubo->maps->no, 1))
		return (false);
	if (!is_empty_file_and_valid_file(cubo->maps->so, 1))
		return (false);
	if (!is_empty_file_and_valid_file(cubo->maps->ea, 1))
		return (false);
	if (!is_empty_file_and_valid_file(cubo->maps->we, 1))
		return (false);
	return (true);
}

bool	validate_color(t_cubo *cub)
{
	int	*floor;
	int	*ceiling;
	int	i;

	i = 0;
	ceiling = cub->maps->ceiling;
	floor = cub->maps->floor;
	if (!floor || !ceiling)
		return (print_error(NOT_FOUND_COLOR), false);
	while (floor[i] && i <= 2)
	{
		if (floor[i] < 0 || floor[i] > 255)
			return (print_error(INVALID_RANGE), false);
		i++;
	}
	i = 0;
	while (ceiling[i] && i <= 2)
	{
		if (ceiling[i] < 0 || ceiling[i] > 255)
			return (print_error(INVALID_RANGE), false);
		i++;
	}
	return (true);
}

bool	all_configs_loaded(t_cubo *cub)
{
	if (cub->maps->ceiling && cub->maps->floor && cub->maps->no && cub->maps->so
		&& cub->maps->we && cub->maps->ea)
		return (true);
	return (false);
}

int	parse_colors_and_texture(t_cubo *cub, char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_just_space_line(lines[i]))
		{
			i++;
			continue ;
		}
		if (all_configs_loaded(cub) || is_map_line(lines[i]))
			break ;
		if (lines[i])
		{
			if (!parse_and_load_texture(cub, lines, i))
				return (-1);
			if (!parse_and_load_colors(cub, lines, i))
				return (-1);
		}
		i++;
	}
	if (!validate_texture(cub) || !validate_color(cub))
		return (-1);
	return (i);
}

bool	flood_fill(t_cubo *cub, char **map, int x, int y)
{
	int		width;
	int		height;
	char	**lines;

	lines = NULL;
	height = 0;
	height = cub->maps->height + 3;
	lines = cub->maps->grid;
	width = get_max_line(lines) + 2;
	if (x < 0 || y < 0 || x >= width || y >= height)
		return (true);
	if (map[y][x] == '1' || map[y][x] == 'v' || map[y][x] == 'X')
		return (true);
	if (ft_strchr("0NSWE", map[y][x]))
	{
		map[y][x] = 'X';
		return (false);
	}
	map[y][x] = 'v';
	(flood_fill(cub, map, x + 1, y), flood_fill(cub, map, x - 1, y));
	(flood_fill(cub, map, x, y + 1), flood_fill(cub, map, x, y - 1));
	(flood_fill(cub, map, x - 1, y + 1), flood_fill(cub, map, x - 1, y - 1));
	(flood_fill(cub, map, x + 1, y + 1), flood_fill(cub, map, x + 1, y - 1));
	return (true);
}
