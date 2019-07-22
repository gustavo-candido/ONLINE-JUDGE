#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  mem[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

int main ()
{
	int N, aux, tot, tam;
	char A[10];
	
	while(scanf("%d", &N)) {
		if (!N) break;
		tot = 0;
		sprintf(A, "%d", N);
		for (tam = strlen(A); tam > 0; tam--) {
			tot+=(mem[tam]*((int)A[strlen(A)-tam]-48));
		}
		printf("%d\n", tot);
	}
}
