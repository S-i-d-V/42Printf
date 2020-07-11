#include "Include/ft_printf.h"

int		main()
{
	char * str = "Test printf";

	ft_printf("%s\n", str);
	ft_printf("%5s\n", str);
	ft_printf("%*s\n", 5, str);

	ft_printf("%-s\n", str);
	ft_printf("%-5s\n", str);
	ft_printf("%-*s\n", 5, str);

	ft_printf("%0s\n", str);
	ft_printf("%05s\n", str);
	ft_printf("%0*s\n", 5, str);

	ft_printf("%.s\n", str);
	ft_printf("%.5s\n", str);
	ft_printf("%.*s\n", 5, str);
}
