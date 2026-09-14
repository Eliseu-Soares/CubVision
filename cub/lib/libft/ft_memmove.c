/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:45:14 by sgaspar           #+#    #+#             */
/*   Updated: 2025/06/30 15:01:12 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	i = -1;
	d = (char *)dest;
	s = (const char *)src;
	if ((dest == src) || (dest == NULL) || (src == NULL))
		return (dest);
	if (d < s)
	{
		while (++i < n)
			d[i] = s[i];
	}
	else
	{
		i = n + 1;
		while (--i > 0)
			d[i - 1] = s[i - 1];
	}
	return (dest);
}
