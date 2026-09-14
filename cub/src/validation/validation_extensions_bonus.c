/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_extensions_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsoares <elsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:29:45 by elsoares          #+#    #+#             */
/*   Updated: 2026/04/01 16:29:46 by elsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubo_bonus.h"

int	pos_xtension(char *str)
{
	int	i;

	i = 0;
	i = ft_strlen(str);
	while (str[i] != '.')
		i--;
	return (i);
}

char	*get_xtension(char *str)
{
	char	*ptr;
	int		i;
	int		pos;

	i = 0;
	pos = pos_xtension(str);
	ptr = NULL;
	while (str[i])
		i++;
	ptr = (char *)malloc(i + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[pos])
	{
		ptr[i] = str[pos];
		pos++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

bool	validation_extension(char *str, char *extension)
{
	char	*xtension;

	xtension = get_xtension(str);
	if (ft_strncmp(xtension, extension, ft_strlen(str) + 1) == 0)
	{
		free(xtension);
		return (true);
	}
	free(xtension);
	return (false);
}
