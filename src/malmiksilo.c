// malmiksilo.c - elmalmiksas komandon de uzanto
// se uzanto tajpos "gcc --version", per tiu funkcio estos: 
// argumentaro[0] == "gcc"
// argumentaro[1] == "--version"
// tia komando prilaboros kaj lancxos poste

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRTOK_DELIM " \t\r\n\a" // por strtok() funkcio, legu "man 3 strtok"

// plibonigi poste
char **malmiksu(char *komando)
{
	unsigned pozicio;
	unsigned bufrodimenso = 32;
	char **signaro = malloc(bufrodimenso * sizeof(char*)); // ni skribos al tiu cxi aron cxiujn signojn de komando
	char *bufro; // buffer

	if (!signaro) { 
		fprintf(stderr, "komandilo: eraro de memornomumigado\n");
		exit(EXIT_FAILURE);
	}
                
	bufro = strtok(komando, STRTOK_DELIM);
	for (pozicio = 0; bufro != NULL; pozicio++) {
		signaro[pozicio] = bufro; // skribigi signareron
                
		if (pozicio >= bufrodimenso) {
			bufrodimenso += 32;
			signaro = realloc(signaro, bufrodimenso * sizeof(char *));
			if (!signaro) { // kontrolado de eraroj
				fprintf(stderr, "komandilo: eraro de memornomumigado\n");
				exit (EXIT_FAILURE);
			}
		}
                        
		bufro = strtok(NULL, STRTOK_DELIM);
	}
        
	signaro[pozicio] = NULL;
        
	return signaro;
}
