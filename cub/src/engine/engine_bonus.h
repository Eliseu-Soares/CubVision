/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:50:17 by sgaspar           #+#    #+#             */
/*   Updated: 2026/04/23 17:45:34 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_BONUS_H
# define ENGINE_BONUS_H
# include "../../cubo_bonus.h"
# define MM_TILE 8
# define MM_OFF_X 12
# define MM_OFF_Y 12

void	raycasting(t_cubo *cubo);
void	render(t_cubo *cubo);
int		update_cubo(void *parm);

#endif
