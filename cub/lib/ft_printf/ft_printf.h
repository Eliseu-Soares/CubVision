/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:32:39 by sgaspar           #+#    #+#             */
/*   Updated: 2025/07/11 14:38:42 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	write_str(char *str);
int	write_unsigned(unsigned int n);
int	write_int(int n);
int	convert_to(char *base, size_t valor);
int	write_prt(void *p);
int	write_char(char c);

#endif
