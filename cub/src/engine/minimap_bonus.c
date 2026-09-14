/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:07:16 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/24 18:07:19 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../event/events_bonus.h"
#include "engine_bonus.h"
#include <sys/time.h>

static void	draw_rect(t_cubo *cubo, t_vec2 p, t_vec2 sz, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < sz.y)
	{
		x = 0;
		while (x < sz.x)
		{
			ft_mlx_pixel_put(&cubo->canva, p.x + x, p.y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_wall(t_cubo *cubo, int y, int x)
{
	int		row_len;
	int		color;
	char	cell;

	color = 0;
	row_len = 0;
	while (y < cubo->maps->height && cubo->maps->grid[y])
	{
		row_len = (int)ft_strlen(cubo->maps->grid[y]);
		x = 0;
		while (x < row_len && cubo->maps->grid[y][x]
			&& cubo->maps->grid[y][x] != '\n')
		{
			cell = cubo->maps->grid[y][x];
			if (cell == '1')
				color = 0xFFFFFF;
			else if (cell == '0')
				color = 0x202020;
			draw_rect(cubo, (t_vec2){MM_OFF_X + x * MM_TILE, MM_OFF_Y + y
				* MM_TILE}, (t_vec2){MM_TILE - 1, MM_TILE - 1}, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_cubo *cubo)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_wall(cubo, y, x);
	draw_rect(cubo, (t_vec2){MM_OFF_X + (int)(cubo->player.x * MM_TILE) - 1,
		MM_OFF_Y + (int)(cubo->player.y * MM_TILE) - 1}, (t_vec2){3, 3},
		0xFF0000);
}
