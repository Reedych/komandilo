#define _POSIX_C_SOURCE 200112L

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "komandilo.h"

void internfunkciaro_cd(char **argumentaro) // dosierujsxangxfunkcio
{
	if (argumentaro[1] == NULL) {
		if (chdir(getenv("HOME")) != 0)
			perror(NOMO); // se uzanto simple tajpis "cd" (senargumente), iros al hejmodosierujo
	}
	else 
		if (chdir(argumentaro[1]) != 0)
			perror(NOMO); // sxangxas dosierujon kaj se io eraros, sciigos
}

void internfunkciaro_print(char **argumentaro)
{
	if (argumentaro[1] == NULL)
		fprintf(stderr, "%s: argumentoj ne plenas, print bezonas unu argumenton\n print <ĉenaro>\n", NOMO);
	else {
		for (unsigned i = 1; argumentaro[i] != NULL; i++)
			printf("%s ", argumentaro[i]);
		putchar('\n');
	}
}

void internfunkciaro_int(char **argumentaro)
{
	if (argumentaro[1] == NULL || argumentaro[2] == NULL || argumentaro[3] == NULL)
		fprintf(stderr, "%s: argumentoj ne plenas, var bazonas tri argumentojn\n int <variablo> <procedo, =, +=, ktp.> <signifo>\n", NOMO);
	else {
		if (strcmp(argumentaro[2], "=") == 0) { // difinas variablon
			if (setenv(argumentaro[1], argumentaro[3], 1) != 0)
				perror(NOMO);
		}
		else if (strcmp(argumentaro[2], "+=") == 0) {
			
		}
		else if (strcmp(argumentaro[2], "-=") == 0) {
		}
		else if (strcmp(argumentaro[2], "/=") == 0) {
		}
		else if (strcmp(argumentaro[2], "*=") == 0) {
		}
		else printf("%s: tiu procedo ne ekzistas\n var <nomo> <=|+=|-=|/=|*=> <signifo>\n", NOMO);
	}
}

void internfunkciaro_lin(char **argumentaro)
{
	if (argumentaro[1] == NULL || argumentaro[2] == NULL || argumentaro[3] == NULL)
		fprintf(stderr, "%s: argumentoj ne plenas, var bazonas tri argumentojn\n lin <variablo> <procedo, =, +=, ktp.> <signifo>\n", NOMO);
	else {}
}

void internfunkciaro_bool(char **argumentaro)
{
	if (argumentaro[1] == NULL || argumentaro[2] == NULL || argumentaro[3] == NULL)
		fprintf(stderr, "%s: argumentoj ne plenas, var bazonas tri argumentojn\n bool <variablo> <procedo, =, +=, ktp.> <signifo>\n", NOMO);
	else {}
}

void internfunkciaro_versio()
{
	printf("%s %s - eta ŝelo\n", NOMO, VERSIO);
}

void internfunkciaro_help() 
{
	internfunkciaro_versio();
	
	printf("\nInternaj komandoj:\n");
	printf("  help - printas helpon (ankaŭ version)\n");
	printf("  versio - printas version\n");
	printf("  eliru - eliras la ŝelon\n");
}

int internfunkciaro_trovo_provu(char **argumentaro)
{
	if (strcmp(argumentaro[0], "cd") == 0) internfunkciaro_cd(argumentaro);
	else if (strcmp(argumentaro[0], "help") == 0) internfunkciaro_help();
	else if (strcmp(argumentaro[0], "versio") == 0 || strcmp(argumentaro[0], "version") == 0) internfunkciaro_versio();
	else if (strcmp(argumentaro[0], "int") == 0) internfunkciaro_int(argumentaro);
	else if (strcmp(argumentaro[0], "lin") == 0) internfunkciaro_lin(argumentaro);
	else if (strcmp(argumentaro[0], "bool") == 0) internfunkciaro_bool(argumentaro);
	else if (strcmp(argumentaro[0], "print") == 0) internfunkciaro_print(argumentaro);
	else if (strcmp(argumentaro[0], "eliru") == 0 || strcmp(argumentaro[0], "exit") == 0) exit(0); // elirilo
	else return 0; // komando ne estas interna
	
	return 1; // komando estas interna kaj estas lancxinta
}
