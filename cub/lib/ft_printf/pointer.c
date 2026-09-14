/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:50:48 by sgaspar           #+#    #+#             */
/*   Updated: 2025/07/07 13:50:48 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_prt(void *p)
{
	int	count;

	if (p == NULL)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += convert_to("0123456789abcdef", (size_t)p);
	return (count);
}
