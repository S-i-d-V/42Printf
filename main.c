#include "Include/ft_printf.h"

int		main()
{
	int len;
	char *str;
	char *str_short;

	len = 5;
	str = "String test";
	str_short = "Str";

	printf("===========\nPour * = %d\n===========\n\n", len);

	ft_printf("MOI :\n*s	->	'%*s'\n", len, str);
	ft_printf("*s	->	'%*s'\n", len, str_short);
	printf("LUI :\n*s	->	'%*s'\n", len, str);
	printf("*s	->	'%*s'\n\n", len, str_short);

	ft_printf("MOI :\n.*s	->	'%.*s'\n", len, str);
	ft_printf(".*s	->	'%.*s'\n", len, str_short);
	printf("LUI :\n.*s	->	'%.*s'\n", len, str);
	printf(".*s	->	'%.*s'\n\n", len, str_short);

	ft_printf("MOI :\n-*s	->	'%-*s'\n", len, str);
	ft_printf("-*s	->	'%-*s'\n", len, str_short);
	printf("LUI :\n-*s	->	'%-*s'\n", len, str);
	printf("-*s	->	'%-*s'\n\n", len, str_short);

	ft_printf("MOI :\n0*s	->	'%0*s'\n", len, str);
	ft_printf("0*s	->	'%0*s'\n", len, str_short);
	printf("LUI :\nUNDEFINED\n");
	return (0);
}
