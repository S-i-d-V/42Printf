#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

//Prototype fonction ft_printf;
int	ft_printf(char *format, ...);

//Prototypes fonctions conversion;
void	flag_c(va_list *args);
void	flag_d(va_list *args);
void	flag_i(va_list *args);
void	flag_s(va_list *args);
void	flag_u(va_list *args);
void	flag_x(va_list *args);
void	flag_xx(va_list *args);

//Prototypes fonctions libft;
void	ft_putchar(char c);
void	ft_putnbr(int nb);

//Prototypes fonctions supp;
unsigned int	ft_itoui(unsigned int nb);
void		ft_puthlow(unsigned int nb);
void		ft_puthup(unsigned int nb);
void		ft_putui(unsigned int nb);

#endif
