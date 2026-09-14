/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:10:04 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/22 19:20:39 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

bool	is_just_space_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!((line[i] >= 7 && line[i] <= 13) || (line[i] == ' ')))
			return (false);
		i++;
	}
	return (true);
}

int	skiping_to_space_diff(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	if (is_just_space_line(line))
		return (-1);
	while (line[i])
	{
		while ((line[i] >= 7 && line[i] <= 13) || line[i] == ' ')
			++i;
		if (!((line[i] >= 7 && line[i] <= 13) || (line[i] == ' ')))
			return (i);
		i++;
	}
	return (-1);
}

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	{
		while ((line[i] >= 7 && line[i] <= 13) || line[i] == ' ')
			i++;
		if (line[i] == '1' || line[i] == '0')
			return (true);
		i++;
	}
	return (false);
}

int	get_max_line(char **lines)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	len = 0;
	while (lines[i])
	{
		len = ft_strlen(lines[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

void	hz_strcpy(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (s2[i + n])
	{
		s1[j] = s2[i];
		i++;
		j++;
	}
}
