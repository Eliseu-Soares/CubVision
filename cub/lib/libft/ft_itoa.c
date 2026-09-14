/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:22:33 by sgaspar           #+#    #+#             */
/*   Updated: 2025/07/05 16:38:42 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	num;

	num = n;
	i = ft_num_len(num);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[i--] = '\0';
	if (!num)
		str[i--] = '0';
	while (num)
	{
		str[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
