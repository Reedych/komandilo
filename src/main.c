#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <locale.h>
#include <getopt.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "komandilo.h"
#include "malmiksilo.h"
#include "lancxilo.h"

void informilo(int tipo) // se tipo estas 0, printos helpon, se 1, printos nur version
{
	if (tipo == 0) {
		printf("Uzado: %s [flagaro]\n", NOMO);
		printf("Flagoj:\n");
		printf("  -h - helpo\n");
		printf("  -v - versio\n");
	}
	else if (tipo == 1) {
		printf("%s %s - eta komandilo\n", NOMO, VERSIO);
	}
}

void nenion_fari(){} // fari nenion 

int main(int argc, char **argv)
{
	int opcio;
	bool cxu_ek = true; // cxu ek la komandilon? Bezonata por getopt
	while ((opcio = getopt(argc, argv, "hv")) != -1) {
		switch (opcio) {
			case 'h':
				cxu_ek = false;
				informilo(0);
				break;
			case 'v':
				cxu_ek = false;
				informilo(1);
				break;
		}
	}
	
	if (cxu_ek == false) exit(0); // se uzanto tajpis komandon, post kiu la Komandilo devas ne starti (ekz. help aux versio), la programo ne startos
	
	setlocale(LC_ALL, "");
	
	char *enkonduko; // input // bufro
	char tujsaluto[128]; // shell prompt
	char **argumentaro; // masivo de argumentoj de uzantkomando, ekz. komandaro[0] == "gcc", komandaro[1] == "--version". Bezonas por lancxo
	int stato = 0; // stato de komandilo, nuligas kiam ajnkiale komandilo findevas

	rl_bind_key('\t', rl_complete); // plenigado kiam "TAB" estas prenita

	do {
		snprintf(tujsaluto, sizeof(tujsaluto), "%s %s ", getenv("USER"), ">"); // plenigi tujsaluto-n kun tujsalutlinio, ekz "ivano > "
		
		enkonduko = readline(tujsaluto); // legu komandon de uzanto
				
		add_history(enkonduko); // aldoni komandon al historio
		
		if (!enkonduko) 
			break; // eraroprilaborado
		
		argumentaro = malmiksu(enkonduko); // komentaro estas en malmiksilo.c
		
		stato = lancxu(argumentaro); // en lancxilo.c

		free(enkonduko); // purigi bufron
	} while (stato); // se stato estos 0, eliros

	return 0;
}
