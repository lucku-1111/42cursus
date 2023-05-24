/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:47:06 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/06 16:02:27 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_info
{
	int			*a;
	int			*b;
	int			a_top;
	int			b_top;
	int			size;
}				t_info;

typedef struct	s_count
{
	int			ra;
	int			rb;
	int			pa;
	int			pb;
}				t_count;

typedef struct	s_pivot
{
	int			p1;
	int			p2;
}				t_pivot;

void			push_swap(int argc, char *argv[]);
void			a_to_b(t_info *info, int size);
void			b_to_a(t_info *info, int size);

void			three_arg(t_info *info);
void			four_arg(t_info *info);
void			five_arg(t_info *info);
void			a_to_b_util(t_info *info, t_count *count, t_pivot point, int size);
void			b_to_a_util(t_info *info, t_count *count, t_pivot point, int size);

void			setnum(t_info *info, int argc, char *argv[]);

void			go_error(void);

int				ft_atoi(char *str, int *result);
int				ft_strlcpy(char *dest, const char *src, size_t size);
void			ft_putstr_fd(char *s, int fd);
void			*ft_calloc(size_t count, size_t size);

char			**ft_split(char const *s, char c);
char			**free_strs(char **strs, int i);

int				*copy_arr(t_info *info, int size, int flag);
void			ft_sort(int *arr, int size);
t_pivot			get_pivot(t_info *info, int size, int flag);
void			small_sort_a(t_info *info, int size);
void			small_sort_b(t_info *info, int size);

void			ra(t_info *info, int flag);
void			rb(t_info *info, int flag);
void			rr(t_info *info);
void			rra(t_info *info, int flag);
void			rrb(t_info *info, int flag);
void			rrr(t_info *info);
void			sa(t_info *info, int flag);
void			sb(t_info *info, int flag);
void			ss(t_info *info);
void			pa(t_info *info);
void			pb(t_info *info);

#endif