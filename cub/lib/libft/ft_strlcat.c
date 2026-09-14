/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:21:59 by sgaspar           #+#    #+#             */
/*   Updated: 2025/06/24 13:36:04 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;	
	size_t	src_len;	
	size_t	i;

	i = 0;
	dst_len = 0;
	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	if (dst_len < size)
	{
		while ((dst_len + i + 1) < size && src[i])
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	return (src_len + dst_len);
}
