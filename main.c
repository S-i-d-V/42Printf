#include "Include/ft_printf.h"

int main()
{	
	int nb;
	int neg;
    int prec;
    int width;

    nb = 456574;
	neg = -456574;
    prec = 5;
    width = 15;
	printf("PRECISION : %d\n", prec);
    printf("LUI . : '%.*d' | '%.*d'\n\n", prec, nb, prec, neg);
	
	ft_printf("MOI . : '%.*d' | '%.*d'\n\n", prec, nb, prec, neg);

    printf("WIDTH : %d\n", width);
    printf("LUI 5 : '%*d' | '%*d'\n", width, nb, width, neg);
    printf("LUI - : '%-*d' | '%-*d'\n", width, nb, width, neg);
    printf("LUI 0 : '%0*d' | '%0*d'\n\n", width, nb, width, neg);
	
	ft_printf("MOI 5 : '%*d' | '%*d'\n", width, nb, width, neg);
    ft_printf("MOI - : '%-*d' | '%-*d'\n", width, nb, width, neg);
    ft_printf("MOI 0 : '%0*d' | '%0*d'\n\n", width, nb, width, neg);

    printf("COMBO : P = %d | W = %d\n", prec, width);
    printf("LUI -. : '%-*.*d' | '%-*.*d'\n", width, prec, nb, width, prec, neg);
    printf("LUI 5. : '%*.*d' | '%*.*d'\n", prec, width, nb, prec, width, neg);
    printf("LUI 0. : '%0*.*d' | '%0*.*d'\n\n", width, prec, nb, width, prec, neg);
	
	ft_printf("MOI -. : '%-*.*d' | '%-*.*d'\n", width, prec, nb, width, prec, neg);
    ft_printf("MOI 5. : '%*.*d' | '%*.*d'\n", prec, width, nb, prec, width, neg);
    ft_printf("MOI 0. : '%0*.*d' | '%0*.*d'\n\n", width, prec, nb, width, prec, neg);
}

/*printf("LUI -. : '%-*.*d'\n", width, prec, neg);
	ft_printf("MOI -. : '%-*.*d'\n", width, prec, neg);
    printf("LUI 0. : '%0*.*d'\n", width, prec, neg);
    ft_printf("MOI 0. : '%0*.*d'\n\n", width, prec, neg);*/
