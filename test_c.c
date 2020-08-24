#include "Include/ft_printf.h"
#include <libc.h>

int main()
{
	int n;
	int precneg;
	int width;

	n = 8;
	precneg = -4;
	width = 4;
	printf("N = %d\n", n);
	printf("LUI : '%.*d'\n", width, precneg, n);
	printf("MOI : '%.*d'\n", width, precneg, n);

	printf("LUI : '%0*.*d'\n", width, precneg, n);
	printf("LUI : '%-*.*d'\n", width, precneg, n);
	printf("LUI : '%*.*d'\n", width, precneg, n);

	ft_printf("MOI : '%0*.*d'\n", width, precneg, n);
	ft_printf("MOI : '%-*.*d'\n", width, precneg, n);
	ft_printf("MOI : '%*.*d'\n", width, precneg, n);
}
