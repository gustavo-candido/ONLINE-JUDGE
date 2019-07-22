#include <stdio.h>
#include <stdlib.h>

main()
{
	int N, c, M, C, *p, i, x=0, j;
	
	scanf("%d", &N);
	
	for (c=0; c<N; c++) {
		scanf("%d %d", &M, &C);
		p = (int*) malloc (sizeof(int)*C);
		for (i=0; i<C; i++) {
			scanf("%d", &p[i]);
		}
		if (x>0) printf("\n");
		for (i=0; i<M; i++) {
			printf("%d ->", i);
			for (j=0; j<C; j++) {
				if (p[j]%M == i) {
					printf(" %d ->", p[j]);
				} 
			}
			printf(" \\");
			printf("\n");
		}
		x++;
	}
}
