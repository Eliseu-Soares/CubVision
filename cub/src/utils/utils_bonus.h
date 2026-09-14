/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:10:13 by sgaspar           #+#    #+#             */
/*   Updated: 2026/03/18 17:10:13 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

typedef struct s_data	t_data_img;
typedef struct s_vec2	t_vec2;
typedef struct s_cubo	t_cubo;

unsigned int	ft_mlx_pixel_get(t_data_img *data, int x, int y);
void			ft_mlx_pixel_put(t_data_img *data, int x, int y, int color);
void			draw_ver_line(t_data_img *canva, t_vec2 pos, int height, \
int color);
int				create_trgb(int t, int color[3]);

#endif
