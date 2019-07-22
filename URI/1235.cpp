#include <stdio.h>
#include <string.h>

main ()
{
     int c=0, z, half, i, j;
     char A [200], B[200];
     scanf("%d", &z);

     while (c<z){
         getchar();
        scanf("%[^\n]", &A);
        half = strlen(A) / 2;

        for (i=0, j=half-1; i<=half; i++, j--) {
            B[i] =  A[j];
        }
        for (i=half, j=strlen(A)-1; i<strlen(A); i++, j--) {
            B[i] =  A[j];
        }

        for (i=0; i<strlen(A); i++) {
            printf("%c", B[i]);
        }
        printf("\n");
        c++;
     }
}