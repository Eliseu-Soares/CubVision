/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:05 by sgaspar           #+#    #+#             */
/*   Updated: 2026/04/23 17:38:18 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H
# define S_WIDTH 1920
# define S_HEIGHT 1024
# define M_WIDTH 24
# define M_HEIGHT 24
# define ROT_SPEED 2.0
# define MOVE_SPEED 0.18
# define PITCH 100

enum	e_key_code
{
	k_ESC = 65307,
	k_w = 119,
	k_s = 115,
	k_a = 97,
	k_d = 100,
	k_left = 65361,
	k_right = 65363
};

enum	e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#endif
