#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_prtf
{
	int ret;
}				t_ptrf;

//Prototype fonction ft_printf;
int	ft_printf(const char *format, ...);

//Prototypes fonctions conversion;
void			flag_c(va_list *args, t_ptrf *struc);
void			flag_d(va_list *args, t_ptrf *struc);
void			flag_i(va_list *args, t_ptrf *struc);
void			flag_s(va_list *args, t_ptrf *struc);
void			flag_u(va_list *args, t_ptrf *struc);
void			flag_x(va_list *args, t_ptrf *struc);
void			flag_prc(va_list *args, t_ptrf *struc);
void			flag_p(va_list *args, t_ptrf *struc);
void			flag_xx(va_list *args, t_ptrf *struc);

//Prototypes fonctions libft;
void			ft_putchar(char c, t_ptrf *struc);
void			ft_putnbr(int nb, t_ptrf *struc);
void			ft_putstr(char *str, t_ptrf *struc);
int				ft_strlen(char *str);

//Prototypes fonctions supp;
void			ft_puthlow(unsigned long long nb, t_ptrf *struc);
void			ft_puthup(unsigned long long nb, t_ptrf *struc);
void			ft_putui(unsigned int nb, t_ptrf *struc);
int				ft_checkflag(char c);
void			innit_struct(t_ptrf *struc);

#endif
