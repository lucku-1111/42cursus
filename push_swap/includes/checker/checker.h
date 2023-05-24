/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:26:29 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/05 15:58:38 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct	s_info
{
	int			*a;
	int			*b;
	int			a_top;
	int			b_top;
	int			size;
}				t_info;

void			checker(int argc, char *argv[]);

void			setnum(t_info *info, int argc, char *argv[]);

void			go_error(void);

int				ft_atoi(char *str, int *result);
int				ft_strlcpy(char *dest, const char *src, size_t size);
void			ft_putstr_fd(char *s, int fd);
void			*ft_calloc(size_t count, size_t size);

int				ft_strcmp(char *s1, char *s2);

char			**ft_split(char const *s, char c);
char			**free_strs(char **strs, int i);

void			ra(t_info *info);
void			rb(t_info *info);
void			rr(t_info *info);
void			rra(t_info *info);
void			rrb(t_info *info);
void			rrr(t_info *info);
void			sa(t_info *info);
void			sb(t_info *info);
void			ss(t_info *info);
void			pa(t_info *info);
void			pb(t_info *info);

#endif