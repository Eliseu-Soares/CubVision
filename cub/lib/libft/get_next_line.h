/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:32:14 by sgaspar           #+#    #+#             */
/*   Updated: 2025/08/11 14:58:03 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>

typedef struct s_gnl
{
	char			*str;
	struct s_gnl	*next;
}	t_gnl;
char	*get_next_line(int fd);
size_t	ft_lst_strlen(t_gnl *lst);
void	*ft_lst_reset(t_gnl *list);

#endif
