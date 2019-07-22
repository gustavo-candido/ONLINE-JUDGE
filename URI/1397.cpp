#include <stdio.h>
main ()
{
    int P, A, B, a=0, b=0, i=0;
    while (scanf("%d", &P) != EOF) {
        if (P==0) {
            break;
        }
        else {
            for (i=0; i<P; i++) {
                scanf ("%d %d", &A, &B);
                if (A>B) {
                    a++;
                }
                if (A<B) {
                    b++;
                }
                if (A==B) {
                    a = a;
                    b = b;
                }
            }
            printf ("%d %d\n", a, b);
        }
        a = 0;
        b = 0;
        i = 0;
    }
}