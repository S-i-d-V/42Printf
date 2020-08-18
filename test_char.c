#include <stdio.h>

int main(int ac, char **av)
{
    int nb;
    int neg;
    int prec;
    int width;

    nb = 456;
    neg = -456;
    prec = 5;
    width = 15;
    printf("PRECISION : %d\n", prec);
    printf(". : '%.*d' | '%.*d'\n\n", prec, nb, prec, neg);

    printf("WIDTH : %d\n", width);
    printf("5 : '%*d' | '%*d'\n", width, nb, width, neg);
    printf("- : '%-*d' | '%-*d'\n", width, nb, width, neg);
    printf("0 : '%0*d' | '%0*d'\n\n", width, nb, width, neg);

    printf("COMBO : P = %d | W = %d\n", prec, width);
    printf("-. : '%-*.*d' | '%-*.*d'\n", width, prec, nb, width, prec, neg);
    printf("5. : '%*.*d' | '%*.*d'\n", prec, width, nb, prec, width, neg);
    printf("0. : '%0*.*d' | '%0*.*d'\n\n", width, prec, nb, width, prec, neg);
}
g