#include "Include/ft_printf.h"

int		main()
{
	int len;
	int pos;
	int neg;

	len = 4;
	pos = -965723;
	neg = 93;

	printf("===========\nPour * = %d\n===========\n\n", len);

	ft_printf("MOI :\n*d	->	'%*d'\n", len, pos);
	ft_printf("*d	->	'%*d'\n", len, neg);
	printf("LUI :\n*d	->	'%*d'\n", len, pos);
	printf("*d	->	'%*d'\n\n", len, neg);

	ft_printf("MOI :\n.*d	->	'%.*d'\n", len, pos);
	ft_printf(".*d	->	'%.*d'\n", len, neg);
	printf("LUI :\n.*d	->	'%.*d'\n", len, pos);
	printf(".*d	->	'%.*d'\n\n", len, neg);

	ft_printf("MOI :\n-*d	->	'%-*d'\n", len, pos);
	ft_printf("-*d	->	'%-*d'\n", len, neg);
	printf("LUI :\n-*d	->	'%-*d'\n", len, pos);
	printf("-*d	->	'%-*d'\n\n", len, neg);

	ft_printf("MOI :\n0*d	->	'%0*d'\n", len, pos);
	ft_printf("0*d	->	'%0*d'\n", len, neg);
	printf("LUI :\n0*d	->	'%0*d'\n", len, pos);
	printf("0*d	->	'%0*d'\n", len, neg);
	return (0);
}
