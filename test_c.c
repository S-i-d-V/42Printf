#include "Include/ft_printf.h"
#include <libc.h>

int main(int ac, char **av)
{
	int n;
	int neg;

	n = atoi(av[1]);
	printf("N = %d\n", n);
	printf("'%-7.3d'\n\n", n);
	printf(". | LUI : '%.1d''%.2d''%.3d''%.4d'\n\n", n, n, n, n);

	printf("W | LUI : '%1d''%2d''%3d''%4d'\n", n, n, n, n);
	printf("- | LUI : '%-1d''%-2d''%-3d''%-4d'\n", n, n, n, n);
	printf("0 | LUI : '%01d''%02d''%03d''%04d'\n\n", n, n, n, n);

	printf("-. | LUI : '%-4.1d''%-3.2d''%-2.3d''%-1.4d'\n", n, n, n, n);
	printf("-. | LUI : '%-1.4d''%-2.3d''%-3.2d''%-4.1d'\n\n", n, n, n, n);

	printf("W. | LUI : '%4.1d''%3.2d''%2.3d''%1.4d'\n", n, n, n, n);
	printf("W. | LUI : '%1.4d''%2.3d''%3.2d''%4.1d'\n\n", n, n, n, n);

	printf("0. | LUI : '%04.1d''%03.2d''%02.3d''%01.4d'\n", n, n, n, n);
	printf("0. | LUI : '%01.4d''%02.3d''%03.2d''%04.1d'\n\n", n, n, n, n);
}

/*
void	ft_d(va_list *args, t_prtf *struc)
{
	int		n;
	char	*str;

	n = va_arg(*args, int);
	if (n < 0)
	{
		struc->neg = 1;
		n = n * -1;
	}
	if (n == 0 && struc->dot && struc->prec == 0)
		str = ft_strdup("");
	else
		str = ft_itoa(n);
	struc->len = ft_strlen(str);
	if (struc->dot && struc->prec < struc->len)
		struc->prec = ft_strlen(str);
	ft_display_int(str, struc);
	free(str);
	str = NULL;
}

void	ft_display_int(char *str, t_prtf *struc)
{
	//1
	if (struc->neg && ((struc->zero && !struc->dot) || (struc->dot && struc->pad)))
		ft_putchar('-', struc);

	//2
	if (struc->pad && !struc->dot)
	{
		if (struc->neg)
			ft_putchar('-', struc);
		ft_strto(str, struc->len, struc);
	}
	else if (struc->dot)
	{
		if (struc->zero || (!struc->pad && struc->width > 0))
			ft_fill(' ', struc->width - struc->prec - struc->len, struc);
		if (struc->neg && (struc->zero || !struc->pad))
			ft_putchar('-', struc);
		ft_fill('0', struc->prec - struc->len, struc);
		ft_strto(str, struc->len, struc);
		if (struc->pad)
			ft_fill(' ', struc->width - struc->prec - struc->len, struc);
	}
	else if (struc->zero && !struc->dot)
	{
		ft_fill('0', struc->width - struc->len - struc->neg, struc);
		ft_strto(str, struc->len, struc);
	}
	else if (struc->width && !struc->pad && !struc->zero)
	{
		ft_fill(' ', struc->width - struc->len - struc->neg, struc);
		if (struc->neg)
			ft_putchar('-', struc);
		ft_strto(str, struc->len, struc);
	}
	else
	{
		ft_strto(str, struc->len, struc);
	}

	//3
	if (struc->pad && !struc->dot)
		ft_fill(' ', struc->width - struc->len - struc->neg, struc);
}*/