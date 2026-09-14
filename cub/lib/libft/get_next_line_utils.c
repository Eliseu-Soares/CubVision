/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:10:23 by sgaspar           #+#    #+#             */
/*   Updated: 2025/07/14 17:10:24 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

size_t	ft_lst_strlen(t_gnl *lst)
{
	size_t	len;
	t_gnl	*list;

	list = lst;
	len = 0;
	while (list != NULL)
	{
		len += ft_strlen(list->str);
		list = list->next;
	}
	return (len);
}

void	*ft_lst_reset(t_gnl *list)
{
	t_gnl	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list->str);
		free(list);
		list = tmp;
	}
	list = NULL;
	return (NULL);
}
