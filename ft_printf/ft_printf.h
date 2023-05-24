/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:28:33 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/15 15:32:56 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_spec{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			errno;
}				t_spec;

typedef struct	s_size{
	int			is_zero_num;
	int			is_zero_prec;
	int			len;
}				t_size;

typedef struct	s_box{
	char		*buf;
	char		*start;
	t_size		size;
	int			i;
}				t_box;

int				ft_printf(const char *format, ...);
t_spec			pars_spec(const char *str, int length, va_list ap, char format);
void			init_spec(t_spec *spec);
int				pars_flag(int c, t_spec *spec);
void			pars_width(const char **str, t_spec *spec, va_list ap);
void			pars_precision(const char **str, t_spec *spec, va_list ap);
int				ft_print_c(t_spec spec, va_list ap);
int				ft_print_s(t_spec spec, va_list ap);
int				ft_get_bufsize_s(t_spec *spec, char *str);
void			ft_bufset_s(t_spec spec, int len_buf, char *str, char *buf);
int				ft_print_p(t_spec spec, va_list ap);
char			*ft_getaddr_p(void *p, t_spec *spec);
int				ft_getaddr_size_p(long long addr, t_spec spec);
int				ft_print_percent(t_spec spec);
int				ft_print_d(t_spec spec, va_list ap);
int				ft_get_numsize_d(long long num, t_spec spec);
int				ft_get_bufsize_d(t_spec spec, int len, int sign);
char			*ft_setbuf_d(long long arg, int bufsize, int len, t_spec spec);
void			ft_setnum_d(long long num, char *tail, t_spec spec);
void			ft_setsign_d(long long num, char **buf, \
				t_spec spec, char *start);
int				ft_print_u(t_spec spec, va_list ap);
int				ft_print_x(t_spec spec, va_list ap);
int				ft_print_upper_x(t_spec spec, va_list ap);
t_size			ft_get_numsize_x(long long num, t_spec spec);
int				ft_get_bufsize_x(t_spec spec, int len);
char			*ft_setbuf_x(long long arg, int bufsize, \
				int isupper, t_spec spec);
void			ft_setnum_x(long long num, char *tail, \
				int isupper, t_spec spec);

#endif
