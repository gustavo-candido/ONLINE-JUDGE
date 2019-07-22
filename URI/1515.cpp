#include <stdio.h>

main ()
{
    int N, i, A, T, menor, x;
    char P[100][50];

    while (scanf("%d", &N) != EOF)
    {
        if (N==0) {
            break;
        }
        else {
                for (i=0; i<N; i++) {
                    getchar();
                    scanf("%s", &P[i]);
                    scanf("%d %d", &A, &T);
                    if (i==0) {
                        menor = A - T;
                        x = i;
                    }
                    else if (A-T < menor) {
                        menor = A - T;
                        x = i;
                    }
                }
                printf("%s\n", P[x]);
        }
    }
}