/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:29:39 by seoklee           #+#    #+#             */
/*   Updated: 2021/01/07 21:48:13 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_list
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
t_list			*ft_lstnew(int fd);
t_list			*ft_lstfind(t_list *lst, int fd);
int				ft_strlen(char *s);
char			*ft_realloc(char *str, int len);
int				ft_bufread(t_list *lst, char **line);
t_list			*ft_lstdel(t_list *head, int fd);
char			*ft_strfree(char *str);

#endif
