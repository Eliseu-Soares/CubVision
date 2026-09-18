/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:15:21 by sgaspar           #+#    #+#             */
/*   Updated: 2026/09/15 15:32:50 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config_bonus.h"
#include "cubo_bonus.h"
#include "./src/utils/utils_bonus.h"
#include "./src/event/events_bonus.h"
#include "./src/engine/engine_bonus.h"
#include "./src/network/udp_receive.h"

void	update_direcao(t_cubo *cubo, char c)
{
	t_vec2	pos;

	pos = (t_vec2){(int)cubo->player.x, (int)cubo->player.y};
	c = cubo->maps->grid[pos.y][pos.x];
	if (c == 'N')
	{
		cubo->dir = (t_2d_f){.x = 0, .y = -1};
		cubo->plane = (t_2d_f){.x = 0.66, .y = 0};
	}
	if (c == 'S')
	{
		cubo->dir = (t_2d_f){.x = 0, .y = 1};
		cubo->plane = (t_2d_f){.x = -0.66, .y = 0};
	}
	if (c == 'E')
	{
		cubo->dir = (t_2d_f){.x = 1, .y = 0};
		cubo->plane = (t_2d_f){.x = 0, .y = 0.66};
	}
	if (c == 'W')
	{
		cubo->dir = (t_2d_f){.x = -1, .y = 0};
		cubo->plane = (t_2d_f){.x = 0, .y = -0.66};
	}
	cubo->maps->grid[pos.y][pos.x] = '0';
}

static int	close_windows(t_cubo *cubo)
{
	mlx_loop_end(cubo->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cubo	cubo;

	if (argc < 2 || argc > 2)
		return (print_error(ERR_CUB_USEGE), -1);
	if (arg_validation(argv[1]) == false)
		return (-1);
	init_cubo(&cubo);
	load_map(argv[1], &cubo);
	if (!parse_file(&cubo))
		return (destroy(&cubo), -1);
	init_windows(&cubo);
	if (init_udp(&cubo))
	{
		destroy(&cubo);
		udp_close(&cubo.udp);
		return (1);
	}
		
	update_direcao(&cubo, 0);
	load_texture_data(&cubo);
	mlx_hook(cubo.win, 17, 1L << 0, close_windows, &cubo);
//  mlx_hook(cubo.win, 2, 1L << 0, key_event, &cubo);
//	mlx_hook(cubo.win, ON_MOUSEMOVE, 1L << 6, mouse_event, &cubo);
	mlx_loop_hook(cubo.mlx, update_cubo, &cubo);
	mlx_loop(cubo.mlx);
	destroy(&cubo);
	udp_close(&cubo.udp);
	return (0);
}
