#include <stdio.h>
#include <stdlib.h>

main ()
{
    int N, custo, **box, i, j, *receita, total, lucro, day;

    while (scanf("%d", &N) !=EOF) {
        scanf("%d", &custo);
        lucro = 0;
        box = (int**)calloc(N,sizeof(int*));
        receita = (int*)calloc(N,sizeof(int));
        for (i=0; i<N; i++) {
            box[i] = (int*)calloc(N,sizeof(int));
            scanf("%d", &receita[i]);
        }
        for (i=0; i<N; i++) {
            total = 0;
            day = 1;
            for (j=i; j<N; j++) {
                total+=receita [j];
                box[i][j] = total - (custo*day);
                if (box[i][j]>lucro) lucro = box[i][j];
                day++;
            }
        }
        printf("%d\n", lucro);
    }
}
