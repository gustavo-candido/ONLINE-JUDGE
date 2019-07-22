#include <stdio.h>
#include <stdlib.h>
main ()
{
    int X[2], Y[2];
    while (1) {
        scanf("%d %d %d %d", &X[0], &Y[0], &X[1], &Y[1]);
        if (X[0]==0 && X[1]==0 && Y[0]==0 && Y[1]==0) {
            break;
        }
        if (X[0]==X[1] && Y[0]==Y[1]) {
            printf("0\n");
        }
        if (X[0]!=X[1] && Y[0]==Y[1]) {
            printf("1\n");
        }
        if (X[0]==X[1] && Y[0]!=Y[1]) {
            printf("1\n");
        }
        if (X[0]!=X[1] && Y[0]!=Y[1] && abs (X[0] - X[1])== abs (Y[0] - Y[1])) {
            printf("1\n");
        }
        if (X[0]!=X[1] && Y[0]!=Y[1] && abs (X[0] - X[1])!= abs (Y[0] - Y[1])) {
            printf("2\n");
        }
    }
}