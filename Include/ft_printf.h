/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:11:39 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/13 15:49:02 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

//A retirer;
#include <stdio.h>

//Declaration d'une structure prtf; (Structure);


typedef struct	s_prtf
{
	int i;
	int ret;

	int pad;	//1 Oui 0 Non
	int zero;	//1 Oui 0 Non
	int dot;	//1 Oui 0 Non
	int side;	//1 FILL AVANT 0 FILL APRES

	int width;	//Precision de largeur
	char fill;	//' ' ou '0' caractere de remplissage
	char type;	//cspdiuxX%

	int len;
	int neg;
}				t_prtf;

//Definition d'une structure pour declarer le tableau de fonction;
typedef struct	s_tab
{
	char c;
	void (*tabFunc)(va_list *, t_prtf *);
}				t_tab;

//Prototype fonction ft_printf;
int	ft_printf(const char *format, ...);

//Prototypes fonction pourcent;
void			ft_prc(va_list *args, t_prtf *struc);

//Prototypes fonctions conversions + width/dot/...;
//	C;
void			ft_c(va_list *args, t_prtf *struc);
void			width_c(char c, t_prtf *struc);
void			pad_c(char c, t_prtf *struc);
void			zero_c(char c, t_prtf *struc);
//	S;
void			ft_s(va_list *args, t_prtf *struc);
void			pad_s(char *str, t_prtf *struc);
void			width_s(char *str, t_prtf *struc);
void			zero_s(char *str, t_prtf *struc);
//	D|I;
void			ft_d(va_list *args, t_prtf *struc);
void			pad_d(char *str, t_prtf *struc);
void			width_d(char *str, t_prtf *struc);
void			zero_d(char *str, t_prtf *struc);
void			dot_d(char *str, t_prtf *struc);
//	U;
void			ft_u(va_list *args, t_prtf *struc);
void			pad_u(char *str, t_prtf *struc);
void			width_u(char *str, t_prtf *struc);
void			zero_u(char *str, t_prtf *struc);
void			dot_u(char *str, t_prtf *struc);
//	X;
void			ft_x(va_list *args, t_prtf *struc);
void			pad_x(char *str, t_prtf *struc);
void			width_x(char *str, t_prtf *struc);
void			zero_x(char *str, t_prtf *struc);
void			dot_x(char *str, t_prtf *struc);
//	XX;
void			ft_xx(va_list *args, t_prtf *struc);
void			pad_xx(char *str, t_prtf *struc);
void			width_xx(char *str, t_prtf *struc);
void			zero_xx(char *str, t_prtf *struc);
void			dot_xx(char *str, t_prtf *struc);
//	P;
void			ft_p(va_list *args, t_prtf *struc);
void			pad_p(char *str, t_prtf *struc);
void			width_p(char *str, t_prtf *struc);
void			zero_p(char *str, t_prtf *struc);
void			dot_p(char *str, t_prtf *struc);

//Prototypes fonctions libc/modif;
//	libft_mod;
void			ft_putchar(char c, t_prtf *struc);
void			ft_putstr(char *str, t_prtf *struc);
int				ft_strlen(char *str);
int				ft_isdigit(int c);
char			*ft_strdup(char *s);
//	xtoa_functions;
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
char			*ft_itoa_hexa(unsigned int n, char *base);
char			*ft_ltoa_hexa(unsigned long long n, char *base);
//	xtoa_necessaries;
int				lennb(int n);
void			itoasign(int *n, unsigned int *sign);
int				ft_lenhexa(unsigned int n);
//	supp_functions;
int				ft_strto(char *str, int n, t_prtf *struc);
void			ft_fill(char c, int n, t_prtf *struc);
char			*ft_revstr(char *str);
int				ft_checkflags(char c);
//	tab_functions;
void			ft_print_specifier(const char *format, va_list *args, t_prtf *struc);
int				ft_checktypes(char c);
//	struct_functions;
void			innit_struct(t_prtf *struc);
void			reset_flags(t_prtf *struc);
void			ft_getfill(t_prtf *struc);
//	parse_functions;
void			ft_parse_pad(char c, t_prtf *struc);
void			ft_parse_zero(char c, t_prtf *struc);
void			ft_parse_dot(const char *format, t_prtf *struc, va_list *args);
void			ft_parse_width(const char *format, t_prtf *struc, va_list *args);
void			ft_parse(const char *format, t_prtf *struc, va_list *args);

#endif
