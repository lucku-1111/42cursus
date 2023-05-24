/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:29:38 by seoklee           #+#    #+#             */
/*   Updated: 2021/01/07 21:45:34 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list		*ft_lstnew(int fd)
{
	t_list	*lst;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	lst->fd = fd;
	lst->buf[0] = '\0';
	lst->next = NULL;
	return (lst);
}

t_list		*ft_lstfind(t_list *lst, int fd)
{
	while (1)
	{
		if (lst->fd == fd)
			return (lst);
		if (lst->next == 0)
			return (lst->next = ft_lstnew(fd));
		lst = lst->next;
	}
}

int			ft_strlen(char *s)
{
	int		i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_realloc(char *str, int len)
{
	int		i;
	char	*new;

	if ((new = (char *)malloc(sizeof(char) * (len + BUFFER_SIZE + 1))) == NULL)
		return (NULL);
	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
		free(str);
	}
	new[i] = '\0';
	return (new);
}

int			ft_bufread(t_list *lst, char **line)
{
	int		i;
	int		j;
	int		find_nl;

	i = ft_strlen(*line);
	if ((*line = ft_realloc(*line, i)) == NULL)
		return (-1);
	j = 0;
	find_nl = 0;
	while (lst->buf[j])
	{
		(*line)[i] = lst->buf[j];
		if (lst->buf[j++] == '\n')
		{
			find_nl = 1;
			break ;
		}
		i++;
	}
	(*line)[i] = '\0';
	i = 0;
	while (lst->buf[j])
		lst->buf[i++] = lst->buf[j++];
	lst->buf[i] = '\0';
	return (find_nl);
}
