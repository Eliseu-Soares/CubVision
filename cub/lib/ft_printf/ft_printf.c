/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:30:14 by sgaspar           #+#    #+#             */
/*   Updated: 2025/07/14 14:22:05 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strchr(char *str, char c)
{
	while (*str && *str != c)
		str++;
	return (*str == c);
}

static	int	write_router(char c, va_list *args)
{
	if (c == 's')
		return (write_str(va_arg(*args, char *)));
	if (c == 'i' || c == 'd')
		return (write_int(va_arg(*args, int)));
	if (c == 'c')
		return (write_char(va_arg(*args, int)));
	if (c == '%')
		return (write_char('%'));
	if (c == 'u')
		return (write_unsigned(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (convert_to("0123456789abcdef", va_arg(*args, unsigned int)));
	if (c == 'X')
		return (convert_to("0123456789ABCDEF", va_arg(*args, unsigned int)));
	if (c == 'p')
		return (write_prt(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!format)
		return (0);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%", format[i]))
				count += write_router(format[i++], &args);
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}
