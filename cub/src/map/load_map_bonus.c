/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:32:41 by elsoares          #+#    #+#             */
/*   Updated: 2026/05/08 19:35:26 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

int	count_line(char *file)
{
	char	*ptr;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	ptr = get_next_line(fd);
	while (ptr)
	{
		i++;
		free(ptr);
		ptr = get_next_line(fd);
	}
	close(fd);
	free(ptr);
	return (i);
}

void	load_map(char *file_path, t_cubo *cubo)
{
	char	*ptr;
	int		i;
	int		fd;

	i = 0;
	fd = open(file_path, O_RDONLY);
	cubo->file = ft_calloc(1, sizeof(t_file));
	if (cubo->file == NULL)
		return ;
	cubo->file->lines = ft_calloc(count_line(file_path) + 1, sizeof(char *));
	if (cubo->file->lines == NULL)
		return ;
	ptr = get_next_line(fd);
	while (ptr)
	{
		cubo->file->lines[i++] = ptr;
		cubo->file->count++;
		ptr = get_next_line(fd);
	}
	close(fd);
}
