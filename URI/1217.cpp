#include <stdio.h>
#include <string.h>

main ()
{
    int N, c, i, f;
    float V, total=0, kg=0;
    char A[10000];

    scanf("%d", &N);
    for (c=1; c<=N; c++) {
        scanf("%f", &V);
        getchar();
        total = total + V;
        scanf("%[^\n]", &A);
        for (i=0, f=1; i<strlen(A); i++) {
            if (A[i] == ' ') f++;
        }
        kg = kg + f;
        printf("day %d: %d kg\n", c, f);
    }
    printf("%.2f kg by day\n", kg/N);
    printf("R$ %.2f by day\n", total/N);
}