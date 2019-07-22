#include <stdio.h>
#include <string.h>

main ()
{
	int N, L, hash;
	char A[10000];
	scanf("%d", &N);
	
	for (int c=0; c<N; c++) {
		scanf("%d", &L);
		hash=0;
		getchar();
		for (int i=0; i<L; i++) {
			gets(A);
			for (int j=0; j<strlen(A); j++){
				hash+=(int)A[j]-65;
				hash+=i;
				hash+=j;
			}
		}
		printf("%d\n", hash);
	}
}
