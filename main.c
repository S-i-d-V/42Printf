#include "Include/ft_printf.h"

int main()
{	
	char *str;
    int prec;
    int width;

    str = "abcdefghij";
    prec = 5;
    width = 15;
	printf("PRECISION : %d\n", prec);
    printf("LUI . : '%.*s'\n\n", prec, str);
	
	ft_printf("MOI . : '%.*s'\n\n", prec, str);

    printf("WIDTH : %d\n", width);
    printf("LUI 5 : '%*s'\n", width, str);
    printf("LUI - : '%-*s'\n", width, str);
    printf("LUI 0 : '%0*s'\n\n", width, str);
	
	ft_printf("MOI 5 : '%*s'\n", width, str);
    ft_printf("MOI - : '%-*s'\n", width, str);
    ft_printf("MOI 0 : '%0*s'\n\n", width, str);

    printf("COMBO : P = %d | W = %d\n", prec, width);
    printf("LUI -. : '%-*.*s'\n", width, prec, str);
    printf("LUI 5. : '%*.*s'\n", prec, width, str);
    printf("LUI 0. : '%0*.*s'\n\n", width, prec, str);
	
	ft_printf("MOI -. : '%-*.*s'\n", width, prec, str);
    ft_printf("MOI 5. : '%*.*s'\n", prec, width, str);
    ft_printf("MOI 0. : '%0*.*s'\n\n", width, prec, str);
}
