/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 17:05:48 by seoklee           #+#    #+#             */
/*   Updated: 2021/09/16 15:08:44 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX_ULL 9223372036854775807ULL
# define MIN_ULL 9223372036854775808ULL

typedef struct s_msg
{
	char	c;
	int		size;
}				t_msg;

void	ft_error(void);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putnbr(int n);

#endif
