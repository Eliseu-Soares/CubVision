/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:19:23 by elsoares          #+#    #+#             */
/*   Updated: 2026/05/09 14:17:14 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

bool	init_t_map_in_cubo(t_cubo **cub)
{
	t_cubo	*aux;

	aux = *cub;
	aux->maps = ft_calloc(sizeof(t_map), 1);
	if (!aux->maps)
		return (false);
	return (true);
}

bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\n');
}

void	set_player_position(t_cubo *cubo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cubo->maps->grid[j])
	{
		i = 0;
		while (cubo->maps->grid[j][i])
		{
			if (ft_strchr("NSWE", cubo->maps->grid[j][i]))
				cubo->player = (t_2d_f){i + 0.2, j + 0.2};
			i++;
		}
		j++;
	}
}

bool	parse_maps(t_cubo *cub, char **lines, int init_map)
{
	int		y;
	int		j;
	int		x;
	char	**new_map;

	if (is_invalid_map(lines + init_map))
		return (false);
	if (check_char_invalid_in_map(lines + init_map))
		return (false);
	new_map = NULL;
	y = 0;
	j = 0;
	x = 0;
	while (lines[init_map + j])
		j++;
	cub->maps->height = j;
	cub->maps->grid = (lines + init_map);
	new_map = fill_new_map(cub->maps->grid, cub->maps->height);
	if (is_invalid_space(lines + init_map))
		return (free_split(new_map), false);
	flood_fill(cub, new_map, 0, 0);
	if (is_map_invalid(new_map))
		return (false);
	set_player_position(cub);
	return (true);
}

bool	parse_file(t_cubo *cub)
{
	char	**lines;
	int		init_map;

	init_map = 0;
	init_t_map_in_cubo(&cub);
	lines = NULL;
	lines = cub->file->lines;
	if (primary_filter_char(lines))
		return (false);
	init_map = parse_colors_and_texture(cub, lines);
	if (init_map == -1)
		return (false);
	if (!parse_maps(cub, lines, init_map))
		return (false);
	return (true);
}
