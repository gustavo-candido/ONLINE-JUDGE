#include <stdio.h>
main ()
{
    int A, B, C;
    while (scanf ("%d %d %d", &A, &B, &C) != EOF) {
        if (A==B && A==C) {
            printf ("*\n");
        }
        else if (A!=B && B==C) {
            printf ("A\n");
        }
        else if (B!=A && A==C) {
            printf ("B\n");
        }
        else if (C!=A && A==B) {
            printf ("C\n");
        }
    }
}