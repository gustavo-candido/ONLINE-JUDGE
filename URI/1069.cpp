#include <stdio.h>
#include <string.h>

main ()
{
    int N, c, x, y, z, i, d;
    char A[10000];

    scanf("%d", &N);
    getchar();
    for (c=0; c<N; c++) {
        gets(A);
        x=0;
        y=0;
        z=0;
        for (i=0; i<strlen(A); i++) {
            if (A[i] == '<') {
                x++;
                z++;
            }
            else if (z>0 && A[i] == '>') {
                y++;
                z--;
            }
        }
        if (z==0) d=x;
        else if (z<0) d=x;
        else if (z>0) d=y;
        printf("%d\n", d);
    }
}