#include "Include/ft_printf.h"

int main()
{	
	int ret;

    ret = printf("'%.*i'", -6, -3);
	printf(" [%d]\n", ret);
	ret = ft_printf("'%.*i'", -6, -3);
	printf(" [%d]\n\n", ret);

	ret = printf("'%.*i'", 6, -3);
	printf(" [%d]\n", ret);
	ret = ft_printf("'%.*i'", 6, -3);
	printf(" [%d]\n\n", ret);
}

/*
	char *str;
	int nb;
    int prec;
    int width;

    str = "abcdefghij";
	nb = 256;
    prec = 5;
    width = 15;

//CHAR;
	printf("==========\nCHAR\n==========\n");
	printf("PRECISION : %d\n", prec);
    printf("LUI . : '%.*c'\n\n", prec, str[0]);
	
	ft_printf("MOI . : '%.*c'\n\n", prec, str[0]);

    printf("WIDTH : %d\n", width);
    printf("LUI 5 : '%*c'\n", width, str[0]);
    printf("LUI - : '%-*c'\n", width, str[0]);
    printf("LUI 0 : '%0*c'\n\n", width, str[0]);
	
	ft_printf("MOI 5 : '%*c'\n", width, str[0]);
    ft_printf("MOI - : '%-*c'\n", width, str[0]);
    ft_printf("MOI 0 : '%0*c'\n\n", width, str[0]);

    printf("COMBO : P = %d | W = %d\n", prec, width);
    printf("LUI -. : '%-*.*c'\n", width, prec, str[0]);
    printf("LUI 5. : '%*.*c'\n\n", prec, width, str[0]);
    //printf("LUI 0. : '%0*.*s'\n\n", width, prec, str[0]);
	
	ft_printf("MOI -. : '%-*.*c'\n", width, prec, str[0]);
    ft_printf("MOI 5. : '%*.*c'\n\n", prec, width, str[0]);
    //ft_printf("MOI 0. : '%0*.*c'\n\n\n", width, prec, str[0]);

	//STRING;
	printf("==========\nSTRING\n==========\n");
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
    ft_printf("MOI 0. : '%0*.*s'\n\n\n", width, prec, str);

	//DECIMAL INT;
	printf("==========\nDECIMAL INT\n==========\n");
	printf("PRECISION : %d\n", prec);
    printf("LUI . : '%.*c'\n\n", prec, nb);
	
	ft_printf("MOI . : '%.*c'\n\n", prec, nb);

    printf("WIDTH : %d\n", width);
    printf("LUI 5 : '%*c'\n", width, nb);
    printf("LUI - : '%-*c'\n", width, nb);
    printf("LUI 0 : '%0*c'\n\n", width, nb);
	
	ft_printf("MOI 5 : '%*c'\n", width, nb);
    ft_printf("MOI - : '%-*c'\n", width, nb);
    ft_printf("MOI 0 : '%0*c'\n\n", width, nb);

    printf("COMBO : P = %d | W = %d\n", prec, width);
    printf("LUI -. : '%-*.*c'\n", width, prec, nb);
    printf("LUI 5. : '%*.*c'\n", prec, width, nb);
    printf("LUI 0. : '%0*.*s'\n\n", width, prec, nb);
	
	ft_printf("MOI -. : '%-*.*c'\n", width, prec, nb);
    ft_printf("MOI 5. : '%*.*c'\n", prec, width, nb);
    ft_printf("MOI 0. : '%0*.*c'\n\n\n", width, prec, nb);
	*/