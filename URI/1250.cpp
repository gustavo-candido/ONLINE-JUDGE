#include <stdio.h>

main ()
{
	int N, T, tiros[10000], cont;
	char moves[10000];
	
	scanf("%d", &N);
	
	for (int c=0; c<N; c++) {
	    scanf("%d", &T);
	    for (int i=0; i<T; i++) {
		scanf("%d", &tiros[i]);
	    }
	    getchar();
	    cont=0;
	    for (int i=0; i<T; i++) {
		scanf("%c", &moves[i]);
		if (moves[i] == 'S' && (tiros[i] == 1 || tiros[i] == 2)) cont++;
		else if(moves[i] == 'J' && tiros[i] > 2) cont++;
	    }
	    printf("%d\n", cont);
	}
}
