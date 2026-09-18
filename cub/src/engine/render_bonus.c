/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:49:14 by sgaspar           #+#    #+#             */
/*   Updated: 2026/09/15 15:42:37 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_bonus.h"
#include <sys/time.h>

static double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec + (double)tv.tv_usec / 1000000.0);
}

int	update_cubo(void *parm)
{
	t_cubo	*cubo;
 	int result = 0; 

	
	cubo = (t_cubo *)parm;
	cubo->old_time = cubo->time;
	cubo->time = get_time();
	cubo->frame_time = cubo->time - cubo->old_time;
	
 	result = udp_receive(&cubo->udp);
	if (result > 0)
	{
		printf("UDP: [%s]\n", cubo->udp.buffer);
		handle_udp_command(cubo, cubo->udp.buffer[0]);
	}
	
	if (cubo->side_rotate)
		rotate(cubo, cubo->side_rotate, cubo->speed_rotate);

	if (cubo->move_direction == 1)
		move_front_back(cubo, 1);
	if (cubo->move_direction == -1)
		move_front_back(cubo, -1);
	render(cubo);
	return (0);
}

void	render(t_cubo *cubo)
{
	raycasting(cubo);
	draw_minimap(cubo);
}
