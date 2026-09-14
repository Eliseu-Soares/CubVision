/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:37:38 by elsoares          #+#    #+#             */
/*   Updated: 2026/07/08 21:35:07 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

bool	validate_pos_signal(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_strchr("1234567890,", color[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	verify_element(char *color)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!ft_strchr(color, ','))
		return (false);
	if (ft_strchr(color, ' '))
		return (false);
	while (color[i])
	{
		if (color[i] == ',')
			++count;
		if (color[i] == ',' && color[i + 1] == '\0')
			return (false);
		if ((color[i] < '0' || color[i] > '9') && color[i] != '+'
			&& color[i] != '-' && color[i] != ',')
			return (false);
		i++;
	}
	if (count > 2 || count < 2)
		return (false);
	return (true);
}

char	*get_value_color(char *raw_color)
{
	char	*colors;
	int		j;

	j = 0;
	colors = NULL;
	raw_color = (raw_color + 2);
	if (!raw_color)
		return (print_error(INVALID_COLOR), NULL);
	j = skiping_to_space_diff(raw_color);
	if (j < 0)
		return (print_error(INVALID_COLOR), NULL);
	raw_color = raw_color + j;
	colors = ft_substr(raw_color, 0, ft_strlen(raw_color) - 1);
	if (!verify_element(colors) || !validate_pos_signal(colors))
	{
		if (colors)
			free(colors);
		return (print_error(INVALID_COLOR), NULL);
	}
	return (colors);
}

int	*array_chr_to_array_int(char *str_color)
{
	char	**aux;
	int		*color;

	aux = NULL;
	color = NULL;
	color = ft_calloc(sizeof(int *), 3);
	if (color == NULL)
		return (NULL);
	if (!ft_strchr(str_color, ','))
		return (print_error(INVALID_COLOR), NULL);
	else if (ft_strchr(str_color, ','))
	{
		aux = ft_split(str_color, ',');
		color[0] = ft_atoi(aux[0]);
		color[1] = ft_atoi(aux[1]);
		color[2] = ft_atoi(aux[2]); 
		free_split(aux); 
	}
	return (color);
}

bool	parse_and_load_colors(t_cubo *cub, char **lines, int i)
{
	char	*colors;
	char	*raw_colors;
	int		*aux;

	colors = NULL;
	raw_colors = NULL;
	raw_colors = lines[i] + skiping_to_space_diff(lines[i]);
	if (strncmp_with_spaces(raw_colors, "C"))
	{
		if (cub->maps->ceiling != NULL)
			return (print_error(MORE_COLOR), false);
		colors = get_value_color(raw_colors);
		if (!colors)
			return (false);
		aux = array_chr_to_array_int(colors);
		cub->maps->ceiling = aux;
		if (colors)
			free(colors);
	}
	if (!get_floor(raw_colors, cub, colors))
		return (false);
	return (true);
}
