#include "Include/ft_printf.h"
#include <stdio.h>

int main()
{
	int nb;
	int nb_neg;
	unsigned int unb;
	char *alpha;
	int ret_moi = 0;
	int ret_ptf = 0;

	nb = 124;
	nb_neg = -178;
	unb = 4365;
	alpha = "Test printf";

	ft_printf("Test CHAR :\n");
	ret_moi = ft_printf("MOI : '%c'\n", alpha[0]);
	ret_ptf = printf("PTF : '%c'\n", alpha[0]);
	printf("PTF : %d | MOI : %d\n\n", ret_ptf, ret_moi);

	ft_printf("Test STRING :\n");
	ret_moi = ft_printf("MOI : '%s'\n", alpha);
	ret_ptf = printf("PTF : '%s'\n", alpha);
	printf("PTF : %d | MOI : %d\n\n", ret_ptf, ret_moi);

	ft_printf("Test INT :\n");
	ret_moi = ft_printf("MOI : '%d'\n", nb);
	ret_ptf = printf("PTF : '%d'\n", nb);
	printf("PTF : %d | MOI : %d\n\n", ret_ptf, ret_moi);

	ft_printf("Test UNSIGNED:\n");
	ret_moi = ft_printf("MOI : '%u'\n", nb_neg);
	ret_ptf = printf("PTF : '%u'\n", nb_neg);
	printf("PTF : %d | MOI : %d\n\n", ret_ptf, ret_moi);

	ft_printf("Test HEXA :\n");
	ret_moi = ft_printf("MOI : '%x' | '%X'\n", nb_neg, nb);
	ret_ptf =printf("PTF : '%x' | '%X'\n", nb_neg, nb);
	printf("PTF : %d | MOI : %d\n\n", ret_ptf, ret_moi);

	ft_printf("Test %% :\n");
	ret_moi = ft_printf("MOI : '%%'\n");
	ret_ptf = printf("PTF : '%%'\n");
	printf("PTF : %d | MOI : %d\n\n", ret_ptf, ret_moi);

	ft_printf("Test PTR:\n");
	ret_moi = ft_printf("MOI : '%p'\n", &nb);
	ret_ptf = printf("PTF : '%p'\n", &nb);
	printf("PTF : %d | MOI : %d\n\n", ret_ptf, ret_moi);

	ft_printf("Return :\n");
	ret_moi = ft_printf("MOI : %c | %s | %p | %d | %i | %u | %x | %X | %%\n", alpha[0], alpha, &nb, nb, nb, nb, nb, nb);
	ret_ptf = printf("PTF : %c | %s | %p | %d | %i | %u | %x | %X | %%\n", alpha[0], alpha, &nb, nb, nb, nb, nb, nb);
	printf("PTF : %d | MOI : %d\n\n", ret_ptf, ret_moi);
	return (0);
}
