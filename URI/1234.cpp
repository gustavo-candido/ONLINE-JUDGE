#include <stdio.h>
#include <string.h>

main ()
{
    int i, x;
    char A[100];


    while (gets(A)) {
        x=0;
        for (i=0; i<strlen(A); i++) {
            if (A[i] >= 65 && A[i] <= 90 && x==0) { x=1; }

            else if (A[i] >= 65 && A[i] <= 90 && x==1) { A[i] = A[i]+32; x=0;}

            else if (A[i] >= 97 && A[i] <= 122 && x==0) { A[i] = A[i]-32; x=1;}

            else if (A[i] >= 97 && A[i] <= 122 && x==1)  { x=0;}
        }
        puts(A);
    }
}
