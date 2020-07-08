#include <stdio.h>

int	main()
{
	int nb;
	int nb_neg;

	nb = 600;
	nb_neg = -600;
	printf("DOT :\n");
	printf(".5d -> %.5d | %.5d -> Precise la largeur minimal. (Le signe '-' ne compate pas\n", nb, nb_neg);
	printf(".2d -> %.2d | %.2d -> Ne peut tronquer un nombre entier.\n", nb, nb_neg);
	printf(".*d -> %.*d | %.*d -> Prend la precision en argument.\n", 5, nb, 5, nb_neg);
	printf(".d  -> %.d | %.d -> Aucun effet si pas de precision.\n\n", nb, nb_neg);

	printf("FILL :\n");
	printf("05d -> %05d | %05d -> Precise la largeur minimal (Le signe '-' compte comme 1\n", nb, nb_neg);
	printf("02d -> %02d | %02d -> Ne peut tronquer un nombre entier.\n", nb, nb_neg);
	printf("0*d -> %0*d | %0*d -> Prend la precision en argument.\n", 5, nb, 5, nb_neg);
	printf("0d  -> %0d | %0d -> Aucun effet si pas de precision.\n\n", nb, nb_neg);

	printf("PADD :\n");
	printf("-5d -> %-5d | %-5d -> Rien ??\n", nb, nb_neg);
	printf("-2d -> %-2d | %-2d -> Rien ?\n", nb, nb_neg);
	printf("-*d -> %-*d | %-*d -> Rien ?\n", 5, nb, 5, nb_neg);
	printf("-d  -> %-d | %-d -> Rien ?\n\n", nb, nb_neg);
}
