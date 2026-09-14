/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:31:37 by sgaspar           #+#    #+#             */
/*   Updated: 2025/06/14 05:30:48 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;
	char		character;

	character = (char)c;
	last_occurrence = NULL;
	if (s != NULL)
	{
		while (*s != '\0')
		{
			if (*s == character)
				last_occurrence = s;
			s++;
		}
		if (character == '\0')
			last_occurrence = s;
	}
	return ((char *)last_occurrence);
}
