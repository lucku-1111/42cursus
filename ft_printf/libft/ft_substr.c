/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 04:35:53 by lucku             #+#    #+#             */
/*   Updated: 2020/12/27 20:52:56 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= start)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
