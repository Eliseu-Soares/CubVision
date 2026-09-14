/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:35:26 by sgaspar           #+#    #+#             */
/*   Updated: 2026/09/14 16:06:45 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_bonus.h"

static void	move_side(t_cubo *cubo, int side)
{
	t_2d_f	player;

	player = cubo->player;
	player.x += cubo->plane.x * MOVE_SPEED * side;
	player.y += cubo->plane.y * MOVE_SPEED * side;
	if (cubo->maps->grid[(int)(player.y)][(int)(player.x)] == '0')
		cubo->player = player;
}

void	rotate(t_cubo *cubo, float angle, float speed)
{
	double	old_dir_x;
	double	old_plane_x;

	angle *= speed * cubo->frame_time;
	old_dir_x = cubo->dir.x;
	cubo->dir.x = cubo->dir.x * cos(angle) - cubo->dir.y * sin(angle);
	cubo->dir.y = old_dir_x * sin(angle) + cubo->dir.y * cos(angle);
	old_plane_x = cubo->plane.x;
	cubo->plane.x = cubo->plane.x * cos(angle) - cubo->plane.y * sin(angle);
	cubo->plane.y = old_plane_x * sin(angle) + cubo->plane.y * cos(angle);
}

void	move_front_back(t_cubo *cubo, int side)
{
	(void)side;
	if (cubo->maps->grid[(int)(cubo->player.y)][(int)(cubo->player.x
			+ (cubo->dir.x * MOVE_SPEED) * side)] == '0')
		cubo->player.x += cubo->dir.x * MOVE_SPEED * side;
	if (cubo->maps->grid[(int)(cubo->player.y + (cubo->dir.y * MOVE_SPEED
				* side))][(int)(cubo->player.x)] == '0')
		cubo->player.y += cubo->dir.y * MOVE_SPEED * side;
}

int	key_event(int key, void *parm)
{
	t_cubo	*cubo;

	cubo = (t_cubo *)parm;
	if (key == k_ESC)
		mlx_loop_end(cubo->mlx);
	if (key == k_w)
		move_front_back(cubo, 1);
	if (key == k_s)
		move_front_back(cubo, -1);
	if (key == k_a)
		move_side(cubo, -1);
	if (key == k_d)
		move_side(cubo, 1);
	if (key == k_left)
		rotate(cubo, -1.0, ROT_SPEED);
	if (key == k_right)
		rotate(cubo, 1.0, ROT_SPEED);
	cubo->updated = 1;
	return (0);
}
