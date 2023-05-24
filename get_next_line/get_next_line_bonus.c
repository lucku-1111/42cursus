/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:29:37 by seoklee           #+#    #+#             */
/*   Updated: 2021/01/07 21:48:52 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstdel(t_list *head, int fd)
{
	t_list		*lst;
	t_list		*save;

	lst = head;
	if (head->fd == fd)
	{
		save = head;
		head = head->next;
		free(save);
		return (head);
	}
	while (lst->next)
	{
		save = lst;
		lst = lst->next;
		if (lst->fd == fd)
		{
			save->next = lst->next;
			free(lst);
			return (head);
		}
	}
	return (head);
}

char	*ft_strfree(char *str)
{
	free(str);
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*lst;
	int				length;
	int				find_nl;

	if (BUFFER_SIZE < 1 || line == NULL || fd < 0)
		return (-1);
	if (head == NULL)
		if ((head = ft_lstnew(fd)) == NULL)
			return (-1);
	if ((lst = ft_lstfind(head, fd)) == NULL)
		return (-1);
	*line = NULL;
	if ((find_nl = ft_bufread(lst, line)) == 1)
		return (find_nl);
	while ((length = read(fd, lst->buf, BUFFER_SIZE)) > 0)
	{
		lst->buf[length] = '\0';
		if ((find_nl = ft_bufread(lst, line)) == 1)
			return (find_nl);
	}
	head = ft_lstdel(head, fd);
	if (length < 0)
		*line = ft_strfree(*line);
	return (length);
}
