/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:22:01 by sgaspar           #+#    #+#             */
/*   Updated: 2026/04/23 12:13:05 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

static enum e_texture	get_dir(t_cubo *cubo)
{
	enum e_texture	surf;

	if (cubo->side == 0 && cubo->ray_dir.x > 0)
		surf = e_E;
	if (cubo->side == 0 && cubo->ray_dir.x < 0)
		surf = e_W;
	if (cubo->side == 1 && cubo->ray_dir.y > 0)
		surf = e_S;
	if (cubo->side == 1 && cubo->ray_dir.y < 0)
		surf = e_N;
	return (surf);
}

static int	get_tex_x(t_cubo *cubo)
{
	double	wall_x;
	int		tex_x;

	if (cubo->side == 0)
		wall_x = cubo->player.y + cubo->perp_wall_dist * cubo->ray_dir.y;
	else
		wall_x = cubo->player.x + cubo->perp_wall_dist * cubo->ray_dir.x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(cubo->texture[get_dir(cubo)].size.x));
	if (cubo->side == 0 && cubo->ray_dir.x > 0)
		tex_x = cubo->texture[e_E].size.x - tex_x - 1;
	if (cubo->side == 0 && cubo->ray_dir.x < 0)
		tex_x = cubo->texture[e_W].size.x - tex_x - 1;
	if (cubo->side == 1 && cubo->ray_dir.y > 0)
		tex_x = cubo->texture[e_S].size.x - tex_x - 1;
	if (cubo->side == 1 && cubo->ray_dir.y < 0)
		tex_x = cubo->texture[e_N].size.x - tex_x - 1;
	return (tex_x);
}

static void	draw_lines(t_cubo *cubo, struct s_point p, int line_h, int x)
{
	double	step;
	double	tex_pos;
	int		color;
	int		y;
	int		tex_y;

	step = 1.0 * cubo->texture[get_dir(cubo)].size.y / line_h;
	tex_pos = (p.start - PITCH - S_HEIGHT / 2.0 + line_h / 2.0) * step;
	y = p.start - 1;
	draw_ver_line(&cubo->canva, (t_vec2){.x = x, .y = 0}, p.start, \
create_trgb(1, cubo->maps->ceiling));
	while (++y < p.end)
	{
		tex_y = (int)tex_pos & (cubo->texture[get_dir(cubo)].size.y - 1);
		tex_pos += step;
		color = ft_mlx_pixel_get(&cubo->texture[get_dir(cubo)].data, \
get_tex_x(cubo), tex_y);
		if (cubo->side == 1)
			color = (color >> 1) & 8355711;
		ft_mlx_pixel_put(&cubo->canva, x, y, color);
	}
	draw_ver_line(&cubo->canva, (t_vec2){.x = x, .y = p.end}, S_HEIGHT, \
create_trgb(1, cubo->maps->floor));
}

void	draw_to_canva(t_cubo *cubo, int x)
{
	double	wall_x;
	int		line_h;
	int		start;
	int		end;

	line_h = (int)(S_HEIGHT / cubo->perp_wall_dist);
	start = -line_h / 2 + S_HEIGHT / 2 + PITCH;
	end = line_h / 2 + S_HEIGHT / 2 + PITCH;
	if (start < 0)
		start = 0;
	if (end >= S_HEIGHT)
		end = S_HEIGHT - 1;
	if (cubo->side == 0)
		wall_x = cubo->player.y + cubo->perp_wall_dist * cubo->ray_dir.y;
	else
		wall_x = cubo->player.x + cubo->perp_wall_dist * cubo->ray_dir.x;
	wall_x -= floor((wall_x));
	draw_lines(cubo, (struct s_point){start, end}, line_h, x);
}
