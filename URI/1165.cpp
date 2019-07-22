#include <stdio.h>
main ()
{
    int T, i=1, N, I, div=0;
    scanf ("%d", &T);
    while (T>=i) {
        scanf ("%d", &N);
        for (I=1; I<=N; I++) {
            if (N%I==0) {
                div++;
            }
        }
    if (div==2) {
        printf("%d eh primo\n", N);
    }
    if (div!=2) {
        printf("%d nao eh primo\n", N);
    }
    i++;
    div=0;
}
}