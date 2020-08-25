/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:11:39 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/25 14:36:41 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_prtf
{
	int	i;
	int	ret;
	int pad;
	int dot;
	int zero;
	int prec;
	int width;
	int neg;
	int	len;
	int precisneg;
}				t_prtf;

typedef struct	s_tab
{
	char c;
	void (*tabfunc)(va_list *, t_prtf *);
}				t_tab;

int				ft_printf(const char *format, ...);

void			ft_prc(va_list *args, t_prtf *struc);
void			ft_c(va_list *args, t_prtf *struc);
void			ft_s(va_list *args, t_prtf *struc);
void			ft_display_string(char *str, t_prtf *struc);
void			ft_d(va_list *args, t_prtf *struc);
void			ft_display_int(char *str, t_prtf *struc);
void			ft_u(va_list *args, t_prtf *struc);
void			ft_display_uint(char *str, t_prtf *struc);
void			ft_x(va_list *args, t_prtf *struc);
void			ft_display_xint(char *str, t_prtf *struc);
void			ft_xx(va_list *args, t_prtf *struc);
void			ft_display_xxint(char *str, t_prtf *struc);
void			ft_p(va_list *args, t_prtf *struc);
void			ft_display_pointer(char *str, t_prtf *struc);

void			ft_putchar(char c, t_prtf *struc);
int				ft_strlen(char *str);
int				ft_isdigit(int c);
char			*ft_strdup(char *s);
int				ft_atoi(char *str);

char			*ft_itoapos(int n);
char			*ft_uitoa(unsigned int n);
char			*ft_itoa_hexa(unsigned long long n, char *base);

int				lennb(int n);
int				ft_lenhexa(unsigned long long n);

void			ft_strto(char *str, int n, t_prtf *struc);
void			ft_fill(char c, int n, t_prtf *struc);
char			*ft_revstr(char *str);

int				ft_isflags(char c);
int				ft_istypes(char c);
int				ft_err_parse(char *format, int i);

void			innit_struct(t_prtf *struc);
void			reset_flags(t_prtf *struc);

void			ft_parse_zero(char *format, t_prtf *struc, va_list *args);
void			ft_parse_pad(char *format, t_prtf *struc, va_list *args);
void			ft_parse_dot(char *format, t_prtf *struc, va_list *args);
void			ft_parse_width(char *format, t_prtf *struc, va_list *args);
void			ft_parse(char *format, t_prtf *struc, va_list *args);

#endif
