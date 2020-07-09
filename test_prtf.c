#include <stdio.h>

int	main()
{
	int nb;
	int nb_neg;
	char *str;
	char *str_short;

	nb = 600;
	nb_neg = -6;
	str = "Test printf";
	str_short = "T";

	//Dot;
	printf("DOT : nb = '%d' | nb_neg = '%d'\n", nb, nb_neg);
	printf(".5d -> '%.5d' | '%.5d' -> Fill de '0' la largeur mininal a partir de la gauche (Le '-' compte).\n", nb, nb_neg);
	printf(".*d -> '%.*d' | '%.*d' -> Prend la precision en argument (5).\n", 5, nb, 5, nb_neg);
	printf(".2d -> '%.2d' | '%.2d' -> Ne peut tronquer un nombre entier prenant plus de place que la precision\n", nb, nb_neg);
	printf(".d  -> '%.d' | '%.d' -> Aucun effet si pas de precision.\n\n", nb, nb_neg);
	
	printf("DOT : str = '%s' | str_short = '%s'\n", str, str_short);
	printf(".5s -> '%.5s' | '%.5s' -> Tronque la string au nombre de char preciser.\n", str, str_short);
	printf(".*s -> '%.*s' | '%.*s' -> Prend la precision en argument (5).\n", 5, str, 5, str_short);
	printf(".2s -> '%.2s' | '%.2s' -> Print simplement str si la precision est plus grande que la string\n", str, str_short);
	printf(".s  -> '%.s' | '%.s' -> Precision par defaut 0 si non preciser.\n\n", str, str_short);

	//Zero
	printf("FILL : nb = '%d' | nb_neg = '%d'\n", nb, nb_neg);
	printf("05d -> '%05d' | '%05d' -> Precise la largeur minimal (Le signe '-' compte comme 1\n", nb, nb_neg);
	printf("0*d -> '%0*d' | '%0*d' -> Prend la precision en argument (5).\n", 5, nb, 5, nb_neg);
	printf("02d -> '%02d' | '%02d' -> Ne peut tronquer un nombre entier prenant plus de place que la precision\n", nb, nb_neg);
	printf("0d  -> '%0d' | '%0d' -> Aucun effet si pas de precision.\n\n", nb, nb_neg);

	printf("FILL : str = '%s' | str_short = '%s'\n", str, str_short);
	printf("Zero ne marche pas avec les strings\n\n");

	//Wildcard
	printf("WILDCARD SEUL / PRECISION SEUL : nb = '%d' | nb_neg = '%d'\n", nb, nb_neg);
	printf("5d -> '%5d' | '%5d'-> Fill de ' ' la largeur mininal a partir de la gauche (Le '-' compte)\n", nb, nb_neg);
	printf("*d -> '%*d' | '%*d'-> Pareil + prend la precision en argument (5).\n\n", 5, nb, 5, nb_neg);

	printf("WILDCARD SEUL / PRECISION SEUL: str = '%s' | str_short = '%s'\n", str, str_short);
	printf("5s -> '%5s' | '%5s' -> Fill de ' ' la largeur mininal a partir de la gauche\n", str, str_short);
	printf("*s -> '%*s' | '%*s' -> Pareil + prend la precision en argument (5).\n\n", 5, str, 5, str_short);

	//Pad;
	printf("PAD : nb = '%d' | nb_neg = '%d'\n", nb, nb_neg);
	printf("-5d -> '%-5d' | '%-5d' -> Fill de ' ' la largeur mininal a partir de la droite (Le '-' compte).\n", nb, nb_neg);
	printf("-*d -> '%-*d' | '%-*d' -> Prend la precision en argument (5).\n", 5, nb, 5, nb_neg);
	printf("-2d -> '%-2d' | '%-2d' -> Ne peut tronquer un nombre entier prenant plus de place que la precision\n", nb, nb_neg);
	printf("-d  -> '%-d' | '%-d' -> Aucun effet si pas de precision.\n\n", nb, nb_neg);
	
	printf("PAD : str = '%s' | str_short = '%s'\n", str, str_short);
	printf("-5s -> '%-5s' | '%-5s' -> Fill de ' ' la largeur mininal a partir de la droite.\n", str, str_short);
	printf("-*s -> '%-*s' | '%-*s' -> Prend la precision en argument (5).\n", 5, str, 5, str_short);
	printf("-2s -> '%-2s' | '%-5s' -> Print simplement str si la string est plus grande que la precision\n", str, str_short);
	printf("-s  -> '%-s' | '%-s' -> Precision par defaut 0 si non preciser.\n", str, str_short);
}
