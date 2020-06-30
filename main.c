#include "Include/ft_printf.h"

int main()
{
	ft_printf("c : %c\nstring : %s\n42 : %d\n42 : %i\n4294967291 :%u\nfffffffb : %x\nDC5C : %X\npourcent : %%\n", 'c', "string", 42, 42, -5, -5, 56412);
}
