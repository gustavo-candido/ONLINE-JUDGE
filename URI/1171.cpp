#include <stdio.h>

 main ()
 {
     int N;
     scanf("%d", &N);

     int A[N], i, j, aux, vez[N], num=0, x[N];

    for (i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }

    for (i=0; i<N; i++) {
        for (j=0; j<N-1; j++) {
            if (A[j] > A[j+1]) {
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }

    for (i=0, j=0; i<N; i++, j++) {
        x[j] = i;
        vez[j] = 1;
        num++;
        while (A[i] == A[i+1]) {
            vez[j]++;
            i++;
        }

    }

    for (i=0, j=0; i<num; i++, j++) {
        printf("%d aparece %d vez(es)\n", A[x[j]], vez[j]);
    }
 }