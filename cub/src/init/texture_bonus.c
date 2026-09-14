/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:59:24 by sgaspar           #+#    #+#             */
/*   Updated: 2026/04/22 16:59:24 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

static void	load_texture_direction(t_cubo *cubo, char *f, enum e_texture d)
{
	cubo->texture[d].data.img = mlx_xpm_file_to_image(cubo->mlx, f, \
&cubo->texture[d].size.x, &cubo->texture[d].size.y);
	cubo->texture[d].data.addr = mlx_get_data_addr(cubo->texture[d].data.img, \
&cubo->texture[d].data.bits_per_pixel, &cubo->texture[d].data.line_length, \
&cubo->texture[d].data.endian);
}

void	load_texture_data(t_cubo *cubo)
{
	load_texture_direction(cubo, cubo->maps->no, e_N);
	load_texture_direction(cubo, cubo->maps->so, e_S);
	load_texture_direction(cubo, cubo->maps->ea, e_E);
	load_texture_direction(cubo, cubo->maps->we, e_W);
}
