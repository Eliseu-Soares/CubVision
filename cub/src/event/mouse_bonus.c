/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:22:29 by sgaspar           #+#    #+#             */
/*   Updated: 2026/09/12 14:44:04 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_bonus.h"
#include "../network/udp_receive.h"

int	mouse_event(int x, int y, void *param)
{
	const int	toler = 50;
	t_cubo		*cubo;

	(void)y;
	cubo = (t_cubo *)param;
	cubo->side_rotate = 0;
	cubo->speed_rotate = ROT_SPEED;
	if (x < (S_WIDTH / 2.0) - toler)
	{
		
		cubo->side_rotate = -1;
		cubo->speed_rotate *= fabs(x / (S_WIDTH / 2.0) - 1);
	}
	if (x > (S_WIDTH / 2.0) + toler)
	{
		cubo->side_rotate = 1;
		cubo->speed_rotate *= (x - S_WIDTH / 2.0) / (S_WIDTH / 2.0);
	}
	init_udp(cubo);
	return (0);
}
