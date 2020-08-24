#include "Include/ft_printf.h"
#include <libc.h>
int main()
{
	printf("'%*.*i'\n", 2, -2, 8);
	ft_printf("'%*.*i'\n", 2, -2, 8);
}