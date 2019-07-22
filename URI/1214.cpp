#include <stdio.h>

main ()
{
    int C, n, s, i, v[1500], j;
    double prom;

    scanf("%d", &C);
    for (i=0; i<C; i++) {
        scanf("%d", &n);
        s=0;
        for (j=0; j<n; j++) {
            scanf("%d", &v[j]);
            s+=v[j];
        }
        prom=s*1.0/n;
        s=0;
        for (j=0; j<n; j++) {
            if (v[j]>prom) s++;
        }
        printf("%.3f%\n", s*1.0/n*100);
    }
}