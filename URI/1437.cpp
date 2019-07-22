#include <stdio.h>

main ()
{
    int N, c=0, i=0, S=0;
    char A[1000];

    while (scanf("%d", &N) != EOF) {
        if (N==0) {
            break;
        }
        else {
            scanf(" %[^\n]", &A);

            while (i<N) {
                if (A[i] == 'D') {
                    S++;
                }
                if (A[i] == 'E') {
                    S--;
                }
                if (S==4 || S==-4) {
                    S=0;
                }
                i++;
            }

            if (S==0) {
                printf("N\n");
            }
            if (S==1 || S==-3) {
                printf("L\n");
            }
            if (S==2 || S==-2) {
                printf("S\n");
            }
            if (S==-1 || S==3) {
                printf("O\n");
            }
            S=0;
            i=0;
        }
    }
}