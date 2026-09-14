/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:08:54 by sgaspar           #+#    #+#             */
/*   Updated: 2026/03/18 18:08:54 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

static void	clean_texture(t_cubo *cubo)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cubo->texture[i].data.img)
			mlx_destroy_image(cubo->mlx, cubo->texture[i].data.img);
		i++;
	}
}

static void	clean_config(t_cubo *cubo, int i)
{
	if (cubo->maps->ea)
		free(cubo->maps->ea);
	if (cubo->maps->we)
		free(cubo->maps->we);
	if (cubo->maps->so)
		free(cubo->maps->so);
	if (cubo->maps->no)
		free(cubo->maps->no);
	if (cubo->maps->ceiling)
		free(cubo->maps->ceiling);
	if (cubo->maps->floor)
		free(cubo->maps->floor);
	if (cubo->maps)
		free(cubo->maps);
	i = -1;
	if (cubo->file->lines)
	{
		while (cubo->file->lines[++i])
			free(cubo->file->lines[i]);
		free(cubo->file->lines);
	}
	if (cubo->file)
		free (cubo->file);
	clean_texture(cubo);
}

void	destroy(t_cubo *cubo)
{
	clean_config(cubo, 0);
	if (cubo->canva.img)
		mlx_destroy_image(cubo->mlx, cubo->canva.img);
	if (cubo->win)
		mlx_destroy_window(cubo->mlx, cubo->win);
	if (cubo->mlx)
	{
		mlx_destroy_display(cubo->mlx);
		free(cubo->mlx);
	}
}
