/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:30:35 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/01 16:30:42 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

bool	arg_check(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) < 4)
		return (false);
	while (str[i])
	{
		if (str[i] == '.')
			return (true);
		i++;
	}
	return (false);
}
