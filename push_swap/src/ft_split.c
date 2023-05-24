/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:49:55 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/05 14:22:10 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_strs(char *str, char c)
{
	int i;
	int count;

	i = 1;
	count = 0;
	if (*str == '\0')
		return (0);
	if (*str != c)
		count++;
	while (str[i])
	{
		if (str[i - 1] == c && str[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	count_strlen(char **str, char c)
{
	int count;

	count = 0;
	while (**str)
	{
		if (**str != c)
			count++;
		else
		{
			(*str)++;
			return (count);
		}
		(*str)++;
	}
	return (count);
}

char		**free_strs(char **strs, int i)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	int		len;
	char	*save;
	char	**strs;

	if (s == NULL)
		return (NULL);
	i = -1;
	count = count_strs((char *)s, c);
	if (!(strs = (char **)ft_calloc(count + 1, sizeof(char *))))
		return (NULL);
	while (++i < count)
	{
		while (*s == c)
			s++;
		save = (char *)s;
		len = count_strlen((char **)&s, c);
		if (!(strs[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (free_strs(strs, i));
		ft_strlcpy(strs[i], save, len + 1);
	}
	return (strs);
}
