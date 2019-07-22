#include <stdio.h>

main ()
{
    int N, K, c, i, f;

    scanf("%d", &N);
    for (c=0; c<N; c++) {
        scanf("%d", &K);
        for (i=0; i<K; i++) {
            scanf("%d", &f);
            if (f==1) printf("Rolien\n");
            else if (f==2) printf("Naej\n");
            else if (f==3) printf("Elehcim\n");
            else if (f==4) printf("Odranoel\n");
        }
    }
}