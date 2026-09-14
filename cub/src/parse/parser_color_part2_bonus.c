/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color_part2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:49:47 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/22 18:54:15 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

bool	get_floor(char *raw_colors, t_cubo *cub, char *colors)
{
	int	*aux;

	if (strncmp_with_spaces(raw_colors, "F"))
	{
		if (cub->maps->floor != NULL)
			return (print_error(MORE_COLOR), false);
		colors = get_value_color(raw_colors);
		if (!colors)
			return (false);
		aux = array_chr_to_array_int(colors);
		cub->maps->floor = aux;
		if (colors)
			free(colors);
	}
	return (true);
}
