#include "Include/ft_printf.h"
#include <stdio.h>

int main()
{
	int nb;
	int nb_neg;
	unsigned int unb;
	char *alpha;

	nb = 124;
	nb_neg = -178;
	unb = 4365;
	alpha = "Test printf";

	ft_printf("Test CHAR :\n");
	ft_printf("MOI : '%c'\n", alpha[0]);
	printf("PTF : '%c'\n\n", alpha[0]);

	ft_printf("Test STRING :\n");
	ft_printf("MOI : '%s'\n", alpha);
	printf("PTF : '%s'\n\n", alpha);

	ft_printf("Test INT :\n");
	ft_printf("MOI : '%d'\n", nb);
	printf("PTF : '%d'\n\n", nb);

	ft_printf("Test UNSIGNED:\n");
	ft_printf("MOI : '%u'\n", nb_neg);
	printf("PTF : '%u'\n\n", nb_neg);

	ft_printf("Test HEXA :\n");
	ft_printf("MOI : '%x' | '%X'\n", nb_neg, nb);
	printf("PTF : '%x' | '%X'\n\n", nb_neg, nb);

	ft_printf("Test %% :\n");
	ft_printf("MOI : '%%'\n");
	printf("PTF : '%%'\n\n");

	ft_printf("Test PTR:\n");
	ft_printf("MOI : '%p'\n", &nb);
	printf("PTF : '%p'\n\n", &nb);

	return (0);
}
