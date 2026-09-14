/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:48:59 by sgaspar           #+#    #+#             */
/*   Updated: 2026/04/23 09:10:39 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_bonus.h"
#include "../utils/utils_bonus.h"

static void	run_dda(t_cubo *cubo)
{
	while (cubo->hit == 0)
	{
		if (cubo->side_dist.x < cubo->side_dist.y)
		{
			cubo->side_dist.x += cubo->delta_dist.x;
			cubo->map.x += cubo->step.x;
			cubo->side = 0;
		}
		else
		{
			cubo->side_dist.y += cubo->delta_dist.y;
			cubo->map.y += cubo->step.y;
			cubo->side = 1;
		}
		if (cubo->maps->grid[cubo->map.y][cubo->map.x] - '0' > 0)
			cubo->hit = 1;
	}
}

static void	set_direction(t_cubo *cubo)
{
	if (cubo->ray_dir.x < 0)
	{
		cubo->step.x = -1;
		cubo->side_dist.x = (cubo->player.x - cubo->map.x) * \
cubo->delta_dist.x;
	}
	else
	{
		cubo->step.x = 1;
		cubo->side_dist.x = (cubo->map.x + 1.0 - cubo->player.x) * \
cubo->delta_dist.x;
	}
	if (cubo->ray_dir.y < 0)
	{
		cubo->step.y = -1;
		cubo->side_dist.y = (cubo->player.y - cubo->map.y) * cubo->delta_dist.y;
	}
	else
	{
		cubo->step.y = 1;
		cubo->side_dist.y = (cubo->map.y + 1.0 - cubo->player.y) * \
cubo->delta_dist.y;
	}
}

static void	prepare_vars(t_cubo *cubo, int x)
{
	cubo->hit = 0;
	cubo->camerax = 2 * x / (double)S_WIDTH - 1;
	cubo->ray_dir.x = cubo->dir.x + cubo->plane.x * cubo->camerax;
	cubo->ray_dir.y = cubo->dir.y + cubo->plane.y * cubo->camerax;
	cubo->map.x = (int)cubo->player.x;
	cubo->map.y = (int)cubo->player.y;
	if (cubo->ray_dir.x == 0)
		cubo->delta_dist.x = 1e30;
	else
		cubo->delta_dist.x = fabs(1 / cubo->ray_dir.x);
	if (cubo->ray_dir.y == 0)
		cubo->delta_dist.y = 1e30;
	else
		cubo->delta_dist.y = fabs(1 / cubo->ray_dir.y);
	set_direction(cubo);
}

void	raycasting(t_cubo *cubo)
{
	int	x;

	x = -1;
	while (++x < S_WIDTH)
	{
		prepare_vars(cubo, x);
		run_dda(cubo);
		if (cubo->side == 0)
			cubo->perp_wall_dist = (cubo->side_dist.x - cubo->delta_dist.x);
		else
			cubo->perp_wall_dist = (cubo->side_dist.y - cubo->delta_dist.y);
		draw_to_canva(cubo, x);
	}
	mlx_put_image_to_window(cubo->mlx, cubo->win, cubo->canva.img, 0, 0);
}
