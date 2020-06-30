#include "Include/ft_printf.h"

int main()
{
	ft_printf("%c %s %d %i %u %x %X %%\n", 'c', "string", 42, 42, -5, -5, 56412);
}
