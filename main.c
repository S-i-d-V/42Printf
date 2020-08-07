#include "Include/ft_printf.h"

int		main()
{
	int len;
	unsigned int pos;
	unsigned int neg;

	len = 4;
	pos = 93;
	neg = -93;

	printf("===========\nPour * = %d\n===========\n\n", len);

	ft_printf("MOI :\n*u	->	'%*u'\n", len, pos);
	ft_printf("*u	->	'%*u'\n", len, neg);
	printf("LUI :\n*u	->	'%*u'\n", len, pos);
	printf("*u	->	'%*u'\n\n", len, neg);

	ft_printf("MOI :\n.*u	->	'%.*u'\n", len, pos);
	ft_printf(".*u	->	'%.*u'\n", len, neg);
	printf("LUI :\n.*u	->	'%.*u'\n", len, pos);
	printf(".*u	->	'%.*u'\n\n", len, neg);

	ft_printf("MOI :\n-*u	->	'%-*u'\n", len, pos);
	ft_printf("-*u	->	'%-*u'\n", len, neg);
	printf("LUI :\n-*u	->	'%-*u'\n", len, pos);
	printf("-*u	->	'%-*u'\n\n", len, neg);

	ft_printf("MOI :\n0*u	->	'%0*u'\n", len, pos);
	ft_printf("0*u	->	'%0*u'\n", len, neg);
	printf("LUI :\n0*u	->	'%0*u'\n", len, pos);
	printf("0*u	->	'%0*u'\n", len, neg);
	return (0);
}
