/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:31:35 by sgaspar           #+#    #+#             */
/*   Updated: 2025/08/11 14:11:58 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void	ft_init(t_gnl *list, t_gnl **start, char **next_line, int *readed)
{
	*next_line = NULL;
	*start = NULL;
	*readed = 1;
	if (list != NULL)
	{
		*start = list;
		*next_line = ft_strchr(list->str, '\n');
	}
}

int	ft_extend_lst_or_init(t_gnl **start, t_gnl **list)
{
	t_gnl	*new;

	new = malloc(sizeof(*new));
	if (BUFFER_SIZE < 1)
		return (0);
	new->str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new == NULL || new->str == NULL)
	{
		ft_lst_reset(*start);
		return (0);
	}
	new->next = NULL;
	if (*list == NULL)
		*start = new;
	else
		(*list)->next = new;
	*list = new;
	return (1);
}

t_gnl	*ft_lst_break(t_gnl *list, char *next_line)
{
	t_gnl	*new;
	size_t	i;

	if (list == NULL || next_line == NULL)
		return (NULL);
	new = malloc(sizeof(*new));
	if (BUFFER_SIZE < 1)
		return (0);
	new->str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new == NULL || new->str == NULL)
		return (NULL);
	new->next = NULL;
	next_line++;
	if (*next_line == '\0')
		return (free(new->str), free(new), NULL);
	i = 0;
	while (next_line[i] != '\0')
	{
		new->str[i] = next_line[i];
		if (i == 0)
			next_line[i] = '\0';
		i++;
	}
	new->str[i] = '\0';
	return (new);
}

char	*ft_lst_to_string(t_gnl *list)
{
	t_gnl	*lst_copy;
	char	*string;
	size_t	len;
	size_t	i;
	size_t	j;

	lst_copy = list;
	len = ft_lst_strlen(list);
	if (len == 0)
		return (ft_lst_reset(list));
	string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (ft_lst_reset(list));
	i = 0;
	while (list != NULL && i < len)
	{
		j = 0;
		while ((list->str)[j] != '\0')
			string[i++] = list->str[j++];
		list = list->next;
	}
	string[i] = '\0';
	ft_lst_reset(lst_copy);
	return (string);
}

char	*get_next_line(int fd)
{
	static t_gnl	*list;
	char			*next_line;
	int				readed;
	t_gnl			*start;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ft_init(list, &start, &next_line, &readed);
	while (next_line == NULL && readed > 0)
	{
		if (ft_extend_lst_or_init(&start, &list) == 0)
			return (NULL);
		readed = read(fd, list->str, BUFFER_SIZE);
		if (readed < 0)
		{
			list = NULL;
			ft_lst_reset(start);
			return (NULL);
		}
		list->str[readed] = '\0';
		next_line = ft_strchr(list->str, '\n');
	}
	list = ft_lst_break(start, next_line);
	return (ft_lst_to_string(start));
}
