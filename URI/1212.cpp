#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main ()
{
    int a, b, i, j, carry, x, y, z;
    char A[20], B[20] ,aux[2], aux2[2];
    while (scanf("%d %d", &a, &b) != EOF) {
        if (a==0 && b==0) break;
        if (a>=b) {
        sprintf(A, "%d", a);
        sprintf(B, "%d", b);
        }
        else if (a<b){
        sprintf(A, "%d", b);
        sprintf(B, "%d", a);
        }
        carry=0;
        z=1;
        for (i=strlen(A)-1, j=strlen(B)-1; i>=0; i--, j--) {
            z--;
            if (z<0) {z=0;}
            aux[0] = A[i];
            aux[1] = '\0';
            aux2[0] = B[j];
            aux2[1] = '\0';
            x = atoi(aux);
            y = atoi (aux2);
            if (x+y+z>=10) {
                carry++;
                z=2;
            }
        }
        if (carry==0) printf("No carry operation.\n");
        else if (carry==1) printf("1 carry operation.\n");
        else if (carry>=2) printf("%d carry operations.\n", carry);
    }
}