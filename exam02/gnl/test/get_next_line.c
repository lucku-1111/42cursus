/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:27:41 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/23 13:42:33 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	s = (char *)str;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (s);
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(str);
	if (i < len)
		len = i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_line(char *tail, int *n)
{
	char	*line;
	int		i;

	i = 0;
	while (tail[i] && tail[i] != '\n')
		i++;
	line = ft_substr(tail, 0, i + 1);
	*n = i + 1;
	return (line);
}

char	*ft_tail(char *tail, int *n)
{
	int	i;

	i = ft_strlen(tail) - *n + 1;
	tail = ft_substr(tail, *n, i);
	return (tail);
}

char	*ft_read(char *tail, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		count;

	count = 1;
	while (count > 0 && ft_strchr(tail, '\n') == NULL)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
			return (NULL);
		buf[BUFFER_SIZE] = '\0';
		if (tail != 0)
			tail = ft_strjoin(tail, buf);
		else
			tail = ft_substr(buf, 0, count);
	}
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail = 0;
	char		*line;
	int			n;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	tail = ft_read(tail, fd);
	if (tail[0] == 0)
	{
		free(tail);
		return (NULL);
	}
	n = 0;
	line = ft_line(tail, &n);
	tail = ft_tail(tail, &n);
	return (line);
}
