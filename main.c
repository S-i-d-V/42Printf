#include "Include/ft_printf.h"
#include <libc.h>
int main()
{
	int n;
	int precneg;
	int width;

	n = -12;
	precneg = 8;
	width = 0;
	printf("N = %d\n", n);
	printf(". LUI : '%p'\n", NULL);
	ft_printf(". MOI : '%p'\n\n", NULL);

	printf(". LUI : '%.5p'\n", NULL);
	ft_printf(". MOI : '%.5p'\n\n", NULL);
	/*printf("0. LUI : '%0*.*d'\n", width, precneg, n);
	printf("-. LUI : '%-*.*d'\n", width, precneg, n);
	printf("W. LUI : '%*.*d'\n\n", width, precneg, n);

	ft_printf("0. MOI : '%0*.*d'\n", width, precneg, n);
	ft_printf("-. MOI : '%-*.*d'\n", width, precneg, n);
	ft_printf("W. MOI : '%*.*d'\n", width, precneg, n);*/
}