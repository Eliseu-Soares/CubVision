/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:30:03 by elsoares          #+#    #+#             */
/*   Updated: 2026/05/09 14:20:27 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

bool	arg_validation(char *arg)
{
	if (!arg_check(arg))
		return (print_error(ERR_FILE_NOT_CUB), false);
	if (!validation_extension(arg, ".cub"))
		return (print_error(ERR_FILE_NOT_CUB), false);
	if (!is_empty_file_and_valid_file(arg, 0))
		return (false);
	return (true);
}

bool	primary_filter_char(char **lines)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (lines[x])
	{
		y = 0;
		while (lines[x][y])
		{
			if (ft_strchr("\a\b\t\v\f\r", lines[x][y]))
				return (print_error(INVALID_CHARACTER), true);
			y++;
		}
		x++;
	}
	return (false);
}
