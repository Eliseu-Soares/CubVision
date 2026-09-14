/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:00:53 by sgaspar           #+#    #+#             */
/*   Updated: 2025/06/28 15:54:31 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (p)
		ft_bzero(p, nmemb * size);
	return (p);
}
