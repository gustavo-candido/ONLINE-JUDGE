#include <stdio.h>

 unsigned long long int tri[1000] = {0}, fi[1000] = {0};
 int max=0, cal=1;

unsigned long long int  fibo (unsigned long long int  x) {
    if (fi[x]!=0)return fi[x];
    if (x == 1) return fi[0];
    else if (x == 0) return fi[1];
    else {
         fi[x] = fibo(x-1) + fibo(x-2);
         return fi[x];
     }
}

main ()
{
    unsigned long long int  N, i, cont, aux;
    char A[50];
    fi[0] = 1;
    fi[1] = 1;
    fibo(500);
    while(scanf("%llu", &N) != EOF) {
        if (tri[N] != 0) printf("%llu\n", tri[N]);
        else {
            cont=cal;
            for(int i = max;cont<=N; i++) {
                aux = fibo(i);
                if (aux % 3 == 0) {
                    tri[cont] = aux;
                    cont++;
                }
                else {
                    sprintf(A, "%llu", aux);
                    for (int j=0; A[j] != '\0'; j++) {
                        if (A[j] == '3') {
                            tri[cont] = aux;
                            cont++;
                            break;
                        }
                    }
                }
                max = i;
            }
            cal =   N;
            printf("%llu\n", tri[N]);
        }
    }
}
