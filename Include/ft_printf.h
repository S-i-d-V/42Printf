/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:11:39 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/09 16:51:12 by ugtheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

//Declaration d'une structure prtf; (Structure);
typedef struct	s_prtf
{
	int i;
	int ret;
}				t_prtf;

typedef struct	s_flags
{
	int pad;	//1 Oui 0 Non
	int zero;	//1 Oui 0 Non
	int side;	//1 Gauche 0 Droite

	int width;	//Precision de largeur
	int len;	//Len de la string ou de l'entier
	char fill;	//' ' ou '0' caractere de remplissage
}				t_flags;

//Definition d'une structure pour declarer le tableau de fonction;
typedef struct	s_tab
{
	char c;
	void (*tabFunc)(va_list *, t_prtf *, t_flags *);
}				t_tab;


//Prototype fonction ft_printf;
int	ft_printf(const char *format, ...);

//Prototypes fonctions conversion;
void			conv_c(va_list *args, t_prtf *struc, t_flags *flags);
void			conv_d(va_list *args, t_prtf *struc, t_flags *flags);
void			conv_i(va_list *args, t_prtf *struc, t_flags *flags);
void			conv_s(va_list *args, t_prtf *struc, t_flags *flags);
void			conv_u(va_list *args, t_prtf *struc, t_flags *flags);
void			conv_x(va_list *args, t_prtf *struc, t_flags *flags);
void			conv_prc(va_list *args, t_prtf *struc, t_flags *flags);
void			conv_p(va_list *args, t_prtf *struc, t_flags *flags);
void			conv_xx(va_list *args, t_prtf *struc, t_flags *flags);

//Prototypes fonctions utils libft;
void			ft_putchar(char c, t_prtf *struc);
void			ft_putnbr(int nb, t_prtf *struc);
void			ft_putstr(char *str, t_prtf *struc);
int				ft_strlen(char *str);
int				ft_isdigit(int c);

//Prototypes fonctions utils conv;
void			ft_puthlow(unsigned long long nb, t_prtf *struc);
void			ft_puthup(unsigned long long nb, t_prtf *struc);
void			ft_putui(unsigned int nb, t_prtf *struc);
int				ft_checktype(char c);

//Prototypes fonctions utils struct;
void			innit_struct(t_prtf *struc);
void			innit_flags(t_flags *flags);

//Prototypes fonctions utils parsing;
void			ft_parse_pad(char c, t_prtf *struc, t_flags *flags);
void			ft_parse_zero(char c, t_prtf *struc, t_flags *flags);
void			ft_parse_precision(const char *format, t_prtf *struc, t_flags *flags, va_list *args);
void			ft_parse(const char *format, t_prtf *struc,t_flags *flags, va_list *args);

#endif
