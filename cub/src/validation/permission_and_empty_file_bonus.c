/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission_and_empty_file_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:27:47 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/28 19:56:04 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

int	open_and_validate_file(char *file, int is_texture)
{
	int	fd;

	fd = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		if (errno == EACCES)
			return (print_error(NO_PERMISSION), -1);
		else if (errno == ENOENT && is_texture == 0)
			return (print_error(NO_EXISTS), -1);
		else if (errno == ENOENT && is_texture == 1)
			return (print_error(TEXTURE_NO_EXISTS), -1);
		return (print_error(INVALID_FILE), -1);
	}
	return (fd);
}

bool	is_empty_file_and_valid_file(char *file, int is_texture)
{
	char	*line;
	int		fd;

	fd = 0;
	line = NULL;
	fd = open_and_validate_file(file, is_texture);
	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (print_error(EMPTY_FILE), false);
	}
	if (line)
		free(line);
	close(fd);
	return (true);
}
