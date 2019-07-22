#include <stdio.h>
#include <string.h>

main ()
{
    char A[1500];
    int i, x;

    while (gets(A) != NULL) {
        x=0;
        for (i=0; i<strlen(A); i++) {
            if (A[i] == '(') x++;
            if (A[i] == ')') x--;
            if (x<0) {
                printf("incorrect\n");
                break;
            }
            if (i+1 == strlen(A) && x!=0) {
                printf("incorrect\n");
            }
            if (i+1 == strlen(A) && x==0) {
                printf("correct\n");
            }
        }
    }
}