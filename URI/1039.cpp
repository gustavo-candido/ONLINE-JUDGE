#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main ()
{
    int R1, X1, Y1, R2, X2, Y2;

    while (scanf("%d %d %d %d %d %d", &R1, &X1, &Y1, &R2, &X2, &Y2) != EOF) {
        if ((X1>=0 && X2>=0) || (X1<0 && X2<0)) X2 = abs (X1-X2);
        else if ((X1>=0 && X2<0) || (X1<0 && X2>=0)) X2 = abs (X1) + abs(X2);
        if ((Y1>=0 && Y2>=0) || (Y1<0 && Y2<0)) Y2 = abs (Y1-Y2);
        else if ((Y1>=0 && Y2<0) || (Y1<0 && Y2>=0)) Y2 = abs (Y1) +abs(Y2);
        if (sqrt((X2*X2)+(Y2*Y2))+R2>R1) printf("MORTO\n");
        else printf("RICO\n");
    }
}
