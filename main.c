#include "Include/ft_printf.h"

int		main()
{
	int len;
	char *str;
	char *str_short;

	len = 10;
	str = "String moyenne";
	str_short = "String";

	printf("============================\nPour len = %d\n", len);

	ft_printf("LONG  : .*s -> %.*s\n\nSHORT : .*s -> %.*s\n", len, str, len, str_short);
	printf("Comparaison :\nLONG  : .*s -> '%.*s'\nSHORT : .*s -> '%.*s'\n\n", len, str, len, str_short);


	ft_printf("LONG  : -*s -> %.*s\n\nSHORT : -*s -> %-*s\n", len, str, len, str_short);
	printf("Comparaison :\nLONG  : -*s -> '%-*s'\nSHORT : -*s -> '%-*s'\n\n", len, str, len, str_short);

	ft_printf("LONG  : *s -> %.*s\n\nSHORT : *s -> %*s\n", len, str, len, str_short);
	printf("Comparaison :\nLONG  : *s -> '%*s'\nSHORT : *s -> '%*s'\n\n", len, str, len, str_short);
}
