#include <stdio.h>
main ()
{
int A, B, C, D;
scanf("%d %d", &A, &B);
if (A>B && A%B==0) {
    printf("Sao Multiplos\n");
} else if (A>B && A%B!=0) {
    printf("Nao sao Multiplos\n");
} else if (B>A && B%A==0) {
    printf("Sao Multiplos\n");
} else if (B>A && B%A!=0) {
    printf("Nao sao Multiplos\n");
} else if (A==B) {
    printf("Sao Multiplos\n");}
}