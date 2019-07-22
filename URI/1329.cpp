#include <stdio.h>

main ()
{
    int x, i=0, Ri, Mar=0, Joa=0;
    while (scanf("%d", &x) != EOF) {
        if (x==0) {
            break;
        }
        else {
            for (i=0; i<x; i++) {
                scanf("%d", &Ri);
                if (Ri == 0) {
                    Mar++;
                }
                else if (Ri == 1) {
                    Joa++;
                }
            }
            printf ("Mary won %d times and John won %d times\n", Mar, Joa);
            Joa = 0;
            Mar = 0;
        }
    }
}