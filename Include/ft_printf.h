/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugotheveny <ugotheveny@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:11:39 by ugtheven          #+#    #+#             */
/*   Updated: 2020/07/09 01:16:44 by ugotheveny       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

//Definition d'un nouveau types; (Structure);
typedef struct	s_prtf
{
	//Index pour parcour le format + valeur de retour;
	int i;
	int ret;
	//Partie flag (A reset);
	int pad;	//1 ou 0
	int zero;	//1 ou 0
	int wc;		//1 ou 0

	int prec;	//Chiffre
	char fill;	//' ' ou '0' caractere de remplissage
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
void			reset_flags(t_prtf *struc);

//Prototypes fonctions utils parsing;
void			ft_parse_pad(char c, t_prtf *struc);
void			ft_parse_zero(char c, t_prtf *struc);
void			ft_parse_precision(const char *format, t_prtf *struc, va_list *args);
void			ft_parse(const char *format, t_prtf *struc, va_list *args);

#endif
