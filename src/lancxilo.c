// lancxilo.c - post cxiaj prilaboroj, komando startas

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "komandilo.h"
#include "internfunkciaro.h"

int lancxu(char **argumentaro)
{
	if (internfunkciaro_trovo_provu(argumentaro) == 1) return 1;
	
	pid_t pid, wpid;
	int stato;
	
	pid = fork();
	if (pid == 0) {
		if (execvp(argumentaro[0], argumentaro) == -1) perror(NOMO);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) {
		perror(NOMO);
		exit(EXIT_FAILURE);
	}
	else {
		do {
			wpid = waitpid(pid, &stato, WUNTRACED);
		} while (!WIFEXITED(stato) && !WIFSIGNALED(stato));
	}
	return 1;
}
