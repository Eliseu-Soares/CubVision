/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:48:14 by sgaspar           #+#    #+#             */
/*   Updated: 2025/07/07 14:02:16 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_int(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		return (count + write_int(n * (-1)));
	}
	if (n > 9)
	{
		count += write_int(n / 10);
	}
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	write_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n > 9)
		count += write_unsigned(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	convert_to(char *base, size_t valor)
{
	int		count;

	count = 0;
	if (valor >= 16)
		count += convert_to(base, valor / 16);
	count += write(1, &(base[valor % 16]), 1);
	return (count);
}
