#include "Include/ft_printf.h"
#include <stdio.h>
#include <libc.h>
int main()
{
	int a;
	int b;
	int ret;
	char	c = 'a';
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	a = 12;
	b = 18;
	ret = printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);
	printf(" | [%d]\n", ret);
	ret = ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);
	ft_printf(" | [%d]\n", ret);
}