/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:57:06 by sgaspar           #+#    #+#             */
/*   Updated: 2025/06/14 01:25:27 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkbtw(int valor, int a, int b)
{
	return (valor >= a && valor <= b);
}

int	ft_isalpha(int c)
{
	return (ft_checkbtw(c, 'a', 'z') || ft_checkbtw(c, 'A', 'Z'));
}
