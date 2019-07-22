#include <stdio.h>
main ()
{
    int N, i=1, Q, C= 0, R=0, S=0, total = 0;
    float pc, pr, ps;
    char T;
    scanf ("%d", &N);
    while (N>=i) {
        scanf ("%d %c", &Q, &T);
        if (T == 'C') {
        C = C + Q;
        }
        if (T == 'R') {
        R = R + Q;
        }
        if (T == 'S') {
        S = S + Q;
        }
        total = total + Q;
        i++;
    }
    pc = (C * 100.00) / total;
    ps = (S * 100.00) / total;
    pr = (R * 100.00) / total;
    printf ("Total: %d cobaias\n", total);
    printf ("Total de coelhos: %d\n", C );
    printf ("Total de ratos: %d\n", R);
    printf ("Total de sapos: %d\n", S);
    printf ("Percentual de coelhos: %.2f %\n", pc);
    printf ("Percentual de ratos: %.2f %\n", pr);
    printf ("Percentual de sapos: %.2f %\n", ps);
}