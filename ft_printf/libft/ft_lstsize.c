/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:34:57 by seoklee           #+#    #+#             */
/*   Updated: 2020/12/26 18:25:50 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		size;

	if (lst == 0)
		return (0);
	size = 1;
	while (lst->next != 0)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
