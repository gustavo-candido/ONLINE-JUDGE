#include <stdio.h>

main ()
{
	int maior, N, aux;
	
	while(scanf("%d", &N) != EOF) {
		maior = -100;
		for (int i=0; i<N; i++) {
			scanf("%d", &aux);
			if (aux > maior) maior = aux;
		}
		if (maior < 10) printf("1\n");
		else if (maior >= 10 && maior < 20) printf("2\n");
		else if (maior >= 20) printf("3\n");
	}
}
