/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:31:18 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/01 16:33:09 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

void	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
}

void	print_error_and_free(char *msg, char *path)
{
	print_error(msg);
	if (path)
		free(path);
}
