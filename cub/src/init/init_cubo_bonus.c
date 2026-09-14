/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:22:02 by sgaspar           #+#    #+#             */
/*   Updated: 2026/03/18 18:22:02 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

int	init_cubo(t_cubo *cubo)
{
	ft_memset(cubo, 0, sizeof(t_cubo));
	cubo->mlx = mlx_init();
	if (!cubo->mlx)
		return (print_error("Error\nInvalid Display\n"), -1);
	return (1);
}

void	init_windows(t_cubo *cubo)
{
	cubo->win = mlx_new_window(cubo->mlx, S_WIDTH, S_HEIGHT, \
"Ray casting");
	cubo->canva.img = mlx_new_image(cubo->mlx, S_WIDTH, S_HEIGHT);
	cubo->canva.addr = mlx_get_data_addr(cubo->canva.img, \
&cubo->canva.bits_per_pixel, &cubo->canva.line_length, &cubo->canva.endian);
	cubo->plane = (t_2d_f){.x = 0, .y = 0.66};
	cubo->color_sky = 0xc8c8c8;
	cubo->color_floor = 0;
	cubo->updated = 1;
}
