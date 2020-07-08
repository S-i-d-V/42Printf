#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_prtf
{
	int i;
	int ret;
}				t_prtf;

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

//Prototypes fonctions libft;
void			ft_putchar(char c, t_prtf *struc);
void			ft_putnbr(int nb, t_prtf *struc);
void			ft_putstr(char *str, t_prtf *struc);
int				ft_strlen(char *str);

//Prototypes fonctions supp;
void			ft_puthlow(unsigned long long nb, t_prtf *struc);
void			ft_puthup(unsigned long long nb, t_prtf *struc);
void			ft_putui(unsigned int nb, t_prtf *struc);
int				ft_checktype(char c);
void			innit_struct(t_prtf *struc);

#endif
