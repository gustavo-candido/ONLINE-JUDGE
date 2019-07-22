#include <stdio.h>
#include <string.h>

main ()
{
    char A[100];
    int i;

    while (gets(A) != NULL) {
        for (i=0; i<strlen(A); i++) {
            if ((A[i]>=65 && A[i]<=77) || (A[i]>=97 && A[i]<=109)) A[i]+=13;
            else if ((A[i]>77 && A[i]<=90) || (A[i]>109 && A[i]<=122)) A[i]-=13;
        }
        puts(A);
    }
}