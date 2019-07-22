#include <stdio.h>
#include <stdlib.h>

main()
{
    int N, c=0, QT, S, menor, val[100], i=0;

    scanf("%d", &N);

    while(c<N) {
            scanf("%d %d", &QT, &S);

            for (i=0; i<QT; i++) {
                scanf(" %d", &val[i]);
                if (i==0) {
                    menor = abs (S - val[i]);
                }
                if (abs(S - val[i]) < menor) {
                    menor =  abs (S - val[i]);
                }
            }
            for (i=0; i<QT; i++) {
                if (abs (S - val[i]) == menor) {
                    printf("%d\n", i+1);
                    break;
                }
            }

        c++;
    }
}