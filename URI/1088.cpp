#include <stdio.h>
#include <stdlib.h>

int shellSort(int *vet, int size) {
    int i , j , value, x=0;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
                x++;
            }
            vet [j + gap] = value;
        }
    }
    return x;
}

main ()
{
	int N, c, i, *A, x;
	while (scanf("%d", &N) != EOF) {
		if (N==0) break;
		A = (int*)malloc (N*sizeof(int));
		x = 0;
		
		for (i=0; i<N; i++){
			scanf("%d", &A[i]);
		} 
		x = shellSort(A, N);
		if (x%2==0) printf("Carlos\n");
		else printf("Marcelo\n");
	}
}