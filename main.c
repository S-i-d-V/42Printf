#include "Include/ft_printf.h"

int main()
{
	char *str;

	str = "abcdefghijklmnopq";
	
	printf("W | LUI : '%-7.5s'\n", str);
	ft_printf("W | MOI : '%-7.5s'\n\n", str);
}

/*	printf("W | LUI : '%1c''%2c''%3c''%4c'\n", c, c, c, c);
	ft_printf("W | MOI : '%1c''%2c''%3c''%4c'\n\n", c, c, c, c);

	printf("- | LUI : '%-1c''%-2c''%-3c''%-4c'\n", c, c, c, c);
	ft_printf("- | MOI : '%-1c''%-2c''%-3c''%-4c'\n\n", c, c, c, c);

	printf(". | LUI : '%.1c''%.2c''%.3c''%.4c'\n", c, c, c, c);
	ft_printf(". | MOI : '%.1c''%.2c''%.3c''%.4c'\n\n", c, c, c, c);

	printf("0 | LUI : '%01c''%02c''%03c''%04c'\n", c, c, c, c);
	ft_printf("0 | MOI : '%01c''%02c''%03c''%04c'\n\n", c, c, c, c);*/