/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:41:33 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/22 18:41:49 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

char	*get_path_texture(char *raw_path)
{
	char	*path_texture;
	int		j;

	j = 0;
	path_texture = NULL;
	raw_path = (raw_path + 3);
	if (!raw_path)
		return (print_error(INVALID_TEXTURE_PATH), NULL);
	j = skiping_to_space_diff(raw_path);
	if (j < 0)
		return (print_error(INVALID_TEXTURE_PATH), NULL);
	raw_path = raw_path + j;
	path_texture = ft_substr(raw_path, 0, ft_strlen(raw_path) - 1);
	return (path_texture);
}

bool	parse_and_load_texture2(char *raw_path, t_cubo *cub)
{
	if (strncmp_with_spaces(raw_path, "NO"))
	{
		raw_path = get_path_texture(raw_path);
		if (!raw_path || cub->maps->no != NULL)
			return (print_error_and_free(MORE_TEXTURE, raw_path), false);
		cub->maps->no = raw_path;
	}
	else if (strncmp_with_spaces(raw_path, "SO"))
	{
		raw_path = get_path_texture(raw_path);
		if (!raw_path || cub->maps->so != NULL)
			return (print_error_and_free(MORE_TEXTURE, raw_path), false);
		cub->maps->so = raw_path;
	}
	return (true);
}

bool	parse_and_load_texture(t_cubo *cub, char **lines, int i)
{
	char	*raw_path;

	raw_path = NULL;
	raw_path = lines[i] + skiping_to_space_diff(lines[i]);
	if (!parse_and_load_texture2(raw_path, cub))
		return (false);
	if (strncmp_with_spaces(raw_path, "WE"))
	{
		raw_path = get_path_texture(raw_path);
		if (!raw_path || cub->maps->we != NULL)
			return (print_error_and_free(MORE_TEXTURE, raw_path), false);
		cub->maps->we = raw_path;
	}
	else if (strncmp_with_spaces(raw_path, "EA"))
	{
		raw_path = get_path_texture(raw_path);
		if (!raw_path || cub->maps->ea != NULL)
			return (print_error_and_free(MORE_TEXTURE, raw_path), false);
		cub->maps->ea = raw_path;
	}
	return (true);
}
