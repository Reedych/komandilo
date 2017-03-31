#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "komandilo.h"

void internfunkciaro_cd(char **argumentaro) // dosierujsxangxfunkcio
{
	if (argumentaro[1] == NULL) {
		if (chdir(getenv("HOME")) != 0) perror(NOMO); // se uzanto simple tajpis "cd" (senargumente), iros al hejmodosierujo
	}
	else if (chdir(argumentaro[1]) != 0) perror (NOMO); // sxangxas dosierujon kaj se io eraros, sciigos
}

void internfunkciaro_versio()
{
	printf("%s %s - eta komandilo\n", NOMO, VERSIO);
}

void internfunkciaro_help() 
{
	internfunkciaro_versio();
	
	printf("\nInternaj komandoj:\n");
	printf("  help - printas helpon (ankaŭ version)\n");
	printf("  versio - printas version\n");
}

int internfunkciaro_trovo_provu(char **argumentaro)
{
	if (strcmp(argumentaro[0], "cd") == 0) internfunkciaro_cd(argumentaro);
	else if (strcmp(argumentaro[0], "help") == 0) internfunkciaro_help();
	else if (strcmp(argumentaro[0], "versio") == 0) internfunkciaro_versio();
	else return 0; // komando ne estas interna
	
	return 1; // komando estas interna kaj estas lancxinta
}
