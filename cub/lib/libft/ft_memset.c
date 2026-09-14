/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:55:09 by sgaspar           #+#    #+#             */
/*   Updated: 2025/06/30 15:01:34 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*src;

	if (s == NULL)
		return (NULL);
	src = s;
	while (src && n > 0)
	{
		*src++ = c;
		n--;
	}
	return (s);
}
