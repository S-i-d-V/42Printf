/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:11:39 by ugtheven          #+#    #+#             */
/*   Updated: 2020/08/07 15:02:31 by ugtheven         ###   ########.fr       */
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

//Prototypes fonctions conversion;
void			conv_c(va_list *args, t_prtf *struc);
void			conv_d(va_list *args, t_prtf *struc);
void			conv_i(va_list *args, t_prtf *struc);
void			conv_s(va_list *args, t_prtf *struc);
void			conv_u(va_list *args, t_prtf *struc);
void			conv_x(va_list *args, t_prtf *struc);
void			conv_prc(va_list *args, t_prtf *struc);
void			conv_p(va_list *args, t_prtf *struc);
void			conv_xx(va_list *args, t_prtf *struc);

//Prototype fonctions affichage conv+specifier;
void			spec_c(va_list *args, t_prtf *struc);
void			spec_d(char *str, t_prtf *struc);
void			spec_i(char *str, t_prtf *struc);
void			spec_u(va_list *args, t_prtf *struc);
void			spec_s(char *str, t_prtf *struc);
void			spec_x(va_list *args, t_prtf *struc);
void			spec_prc(va_list *args, t_prtf *struc);
void			spec_p(va_list *args, t_prtf *struc);
void			spec_xx(va_list *args, t_prtf *struc);

//Test
void			pad_s(char *str, t_prtf *struc);
void			width_s(char *str, t_prtf *struc);
void			zero_s(char *str, t_prtf *struc);

void			pad_d(char *str, t_prtf *struc);
void			width_d(char *str, t_prtf *struc);
void			zero_d(char *str, t_prtf *struc);
void			dot_d(char *str, t_prtf *struc);

//Prototypes fonctions utils libft;
void			ft_putchar(char c, t_prtf *struc);
void			ft_putnbr(int nb, t_prtf *struc);
void			ft_putstr(char *str, t_prtf *struc);
int				ft_strlen(char *str);
int				ft_isdigit(int c);
int				ft_strto(char *str, int n, t_prtf *struc);
void			ft_fill(char c, int n, t_prtf *struc);
char			*ft_itoa(int n);
char			*ft_strdup(char *s);

//Prototypes dependances libft;
int				lennb(int n);
void			itoasign(int *n, unsigned int *sign);

//Prototypes fonctions utils conv;
void			ft_puthlow(unsigned long long nb, t_prtf *struc);
void			ft_puthup(unsigned long long nb, t_prtf *struc);
void			ft_putui(unsigned int nb, t_prtf *struc);
int				ft_checktype(char c);

//Prototypes fonctions utils struct;
void			innit_struct(t_prtf *struc);
void			reset_flags(t_prtf *struc);
void			ft_getfill(t_prtf *struc);

//Prototypes fonctions utils parsing;
void			ft_parse_pad(char c, t_prtf *struc);
void			ft_parse_zero(char c, t_prtf *struc);
void			ft_parse_dot(const char *format, t_prtf *struc, va_list *args);
void			ft_parse_width(const char *format, t_prtf *struc, va_list *args);
void			ft_parse(const char *format, t_prtf *struc, va_list *args);

//Prototypes fonctions utils print;
void			ft_print_specifier(const char *format, va_list *args, t_prtf *struc);

//Temporaire;
void	ft_print_struc(t_prtf struc);

#endif
